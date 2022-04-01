const int a = 8; // For displaying segment "a"
const int b = 9; // For displaying segment "b"
const int c = 4; // For displaying segment "c"
const int d = 5; // For displaying segment "d"
const int e = 6; // For displaying segment "e"
const int f = 2; // For displaying segment "f"
const int g = 3; // For displaying segment "g"

bool bPress = false;
const int buttonPin = 10;

// value changes, when button be pressed
int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;  // current state of the button
int lastButtonState = 0;  // previous state of the button


void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  // using the internal pull up resistor in arduino 
  // In the case of a simple switch, this causes the pin to read HIGH when the switch is open, and LOW when the switch is pressed
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  displayDigit(buttonPushCounter);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(buttonPin);

  // comapare the buttonState to its previous state
  if(buttonState != lastButtonState){
    // if the buttonState has changed, increment the counter
    // because using the internal pull up resistor, if the button is not pressed, the level should be high
    // if the button is being pressed, the level is low
    if(buttonState == LOW){
      bPress = true;
      buttonPushCounter++;
      if(buttonPushCounter > 9){
        buttonPushCounter = 0;
        Serial.println("on");
      }
    }
    else{
      Serial.println("off");
    }
    delay(50);
  }

  lastButtonState = buttonState;

  if(bPress){
    turnOff();
    displayDigit(buttonPushCounter);
  }
}


void turnOff(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void displayDigit(int digit){
  //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);

 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);

 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);

 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);

 //Conditions for displaying segment e
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);

 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);

 //Conditions for displaying segment g
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);
}
