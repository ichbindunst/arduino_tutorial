// explanation of hardware connection
/**
  1. stepmotor can only be runned with a stepmotor driver, because the stepmotor
     draws a lot of current while running, so it cannot be directly drived by arduino
  2. Because of 1., a exteral power supply with 9V should be used, and in order to use
     this power supply, a exteral power supply module should be added, in order to provide
     sufficient current to the stepmotor, this module should be connected to the stepmotor 
     driver
**/


// this file can be found at
// https://github.com/arduino-libraries/Stepper/blob/master/src/Stepper.h

#include <Stepper.h>

int stepsPerRevolution = 2048;

// unit: rpm
int motSpeed = 10; 


// push button and change the rotate direction of stepmotor
int buttonPin = 2;
int motDir = 1;
int buttonValNew;
int buttonValOld = 1;


// ATTENTION! the pin of 28BYJ48 dosent reliable
//Stepper myStepper(stepsPerRevolution, 9, 11, 10, 8); // working 
//Stepper myStepper(stepsPerRevolution, 10, 8, 11, 9);  // working
Stepper myStepper(stepsPerRevolution, 10, 8, 9, 11);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  myStepper.setSpeed(motSpeed);

  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {

  // keep reading the button value
  buttonValNew = digitalRead(buttonPin);
  
  // at first the button value will be set to 1, buttonValOld = 1
  // if the button is pushed, the value will be change into 0
  // ATTENTION! The reading speed of digitalRead is not really sensible
  // when pushing button, please push for at least 0.5 second

  
  // when the button is pushed
  if(buttonValOld == 1 && buttonValNew == 0){
     motDir = motDir*(-1);
  }

  myStepper.step(motDir*1);

  /**
    * control the rotate angle of stepmotor
  myStepper.step(stepsPerRevolution);
  delay(1000);
  myStepper.step(-stepsPerRevolution);
  delay(1000);
  **/
}
