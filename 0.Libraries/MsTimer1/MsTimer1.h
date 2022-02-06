#ifndef MsTimer1_h
#define MsTimer1_h

#include <avr/interrupt.h>

namespace MsTimer1 {
	extern unsigned long msecs;
	extern void (*func)();
	extern volatile unsigned long count;
	extern volatile char overflowing;
	extern volatile unsigned int tcnt1;
	
	void set(unsigned long ms, void (*f)());
	void start();
	void stop();
	void _overflow();
}

#endif

