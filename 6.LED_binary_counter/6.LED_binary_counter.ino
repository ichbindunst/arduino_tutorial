// LED binary counter
// MSB  MSB-1  MSB-2  MSB-3
// red  green  blue   yellow

int red = 13;
int green = 12;
int blue = 11;
int yellow = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // 0
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(500);

  // 1
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);

  // 2
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, LOW);
  delay(500);

  // 3
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, HIGH);
  delay(500);

  // 4
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(500);

  // 5
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);

  // 6
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, LOW);
  delay(500);

  // 7
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, HIGH);
  delay(500);

  // 8
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(500);

  // 9
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);

  // 10
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, LOW);
  delay(500);

  // 11
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, HIGH);
  delay(500);

  // 12
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(500);

  // 13
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);

  // 14
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, LOW);
  delay(500);

  // 15
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, HIGH);
  delay(500);



}
