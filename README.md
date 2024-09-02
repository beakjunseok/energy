    if(text == "welcome!"){
      Serial.println("모터쪽으로 가는 신호");
      myStepper.step(-40960);
      delay(1000);
      delay(5000);
      digitalWrite(7,HIGH);
    }
    else if(text == "goodbye!"){
      Serial.println("모터에서 멀어지는 신호");
      myStepper.step(40960);
      delay(1000);
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
