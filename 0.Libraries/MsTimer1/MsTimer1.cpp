#include "MsTimer1.h"

unsigned long MsTimer1::msecs;
void (*MsTimer1::func)();
volatile unsigned long MsTimer1::count;
volatile char MsTimer1::overflowing;
volatile unsigned int MsTimer1::tcnt1;

void MsTimer1::set(unsigned long ms, void (*f)()) {
	float prescaler = 0.0;

	TIMSK1 &= ~(1<<TOIE1);         
	TCCR1A &= ~((1<<WGM11) | (1<<WGM10));
	TCCR1B &= ~(1<<WGM12);
	TIMSK1 &= ~(1<<OCIE1A);

	if ((F_CPU >= 1000000UL) && (F_CPU <= 16000000UL)) {  //256分频
		TCCR1B |= (1<<CS12);
		TCCR1B &= ~((1<<CS11) | (1<<CS10));
		prescaler = 256.0;
	}

    //算出1ms数多少次                     //1ms
	tcnt1 = 65536 - (int)((float)F_CPU * 0.001 / prescaler);

	if (ms == 0)
		msecs = 1;
	else
		msecs = ms;

	func = f;
}

void MsTimer1::start() {
	count = 0;
	overflowing = 0;
	TCNT1 = tcnt1;
	TIMSK1 |= (1<<TOIE1);
}

void MsTimer1::stop() {
	TIMSK1 &= ~(1<<TOIE1);
}

void MsTimer1::_overflow() {
	count += 1;

	if (count >= msecs && !overflowing) {
		overflowing = 1;
		count = 0;
		(*func)();
		overflowing = 0;
	}
}

ISR(TIMER1_OVF_vect) {

	TCNT1 = MsTimer1::tcnt1;
 
	MsTimer1::_overflow();
}
