/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/
//hello this code uploaded
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int status1 = 6;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
bool off_flag = false;
bool flag = false;
void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(status1, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  digitalWrite(status1,LOW);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    Serial.println(buttonState);
    digitalWrite(ledPin, HIGH);
    if(flag != 1){
      delay(2000);
      while(!digitalRead(buttonPin)&&(flag != 1)){
      Serial.println("High....");
      digitalWrite(status1,HIGH);
      delay(2000);
      break;
      }
     Serial.println("Out of while....");
     digitalWrite(status1,LOW);
    flag = 1;
    }
    Serial.println("A");
    
  } else {
    // turn LED off:
    Serial.println(buttonState);
    if(flag == 1){
    Serial.println("LOW....");
     digitalWrite(status1,HIGH);
    delay(2000);
    flag = 0;
    }
     digitalWrite(status1,LOW);
    Serial.println("B....");
  }
}
