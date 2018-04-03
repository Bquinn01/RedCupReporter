const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0; 
int count = 0; 
#include "config.h"
AdafruitIO_Feed *counter = io.feed("counter");
void setup() {
Serial.begin(9600);
while(! Serial);
 Serial.print("Connecting to Adafruit IO");
 io.connect();
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());


  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

}

void loop() {
   io.run(); 
    // save count to the 'counter' feed on Adafruit IO
    if (buttonPushCounter >= 35) {
  Serial.print("sending -> ");
  Serial.println(count);
  counter->save(count);
  count++;
    }
 

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
if (buttonState != lastButtonState) {
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    buttonPushCounter++;

      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
   }
   }
    lastButtonState = buttonState;

    // turn LED on:
    
   // if (count >= 35) {
   //   digitalWrite(ledPin, HIGH);
  //    count = 0;
 // } else {
    // turn LED off:
   // digitalWrite(ledPin, LOW);
 // }

if (buttonPushCounter >= 35) {
      buttonPushCounter = 0;
}
}
 
