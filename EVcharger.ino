#include <SoftwareSerial.h>
#include <Stepper.h>

SoftwareSerial HC06(2, 3);


const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution,11,9,10,8); 



void setup() {
  Serial.begin(9600);
  HC06.begin(9600);
  myStepper.setSpeed(15); 
  pinMode(7,OUTPUT);
}

void loop() {
  if(HC06.available()){
    String text = HC06.readStringUntil(0x0A);
    if(text == "welcome!"){
      Serial.println("모터쪽으로 가는 신호");
      myStepper.step(-40960);
      delay(5000);
      digitalWrite(7,HIGH);
    }
    else if(text == "goodbye!"){
      Serial.println("모터에서 멀어지는 신호");
      myStepper.step(40960);
      delay(5000);
      digitalWrite(7,HIGH);
    }
    else if(text == "led!"){
      Serial.println("LED OFF 신호");
      delay(100);
      digitalWrite(7,LOW);
    }
    Serial.println(text);
  }

  if(Serial.available()){
    String text = Serial.readStringUntil(0x0A);
    HC06.println(text);
  }
}
