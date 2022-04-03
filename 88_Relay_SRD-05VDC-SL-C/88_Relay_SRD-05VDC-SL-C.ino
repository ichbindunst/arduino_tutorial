// technically, relay is a switch which using the small current to control the large current
// normally, when we supply with DC motor, we should use 9V battery to supply
// but with relay, technically we could just using the arduino board to supply

#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // back and forth example
  Serial.println("One way, then reverse");
  digitalWrite(ENABLE, HIGH);   // enable on
  for(i = 0; i < 5; i++){
    digitalWrite(DIRA, HIGH);  // one way
    digitalWrite(DIRB, LOW);
    delay(750);
    digitalWrite(DIRA, LOW);  // reverse
    digitalWrite(DIRB, HIGH);
    delay(750);
  }

  digitalWrite(ENABLE, LOW); // disbale
  delay(3000);
  for(i = 0; i < 5; i++){
    digitalWrite(DIRA, HIGH);  // one way
    digitalWrite(DIRB, LOW);
    delay(750);
    digitalWrite(DIRA, LOW);  // reverse
    digitalWrite(DIRB, HIGH);
    delay(750);
  }

  digitalWrite(ENABLE, LOW);  // disable
  delay(3000);
}
