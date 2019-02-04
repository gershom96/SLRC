void brakes(){

    
  digitalWrite(MOTLA,HIGH);
  digitalWrite(MOTLB,HIGH);
  digitalWrite(MOTLEN,HIGH);
  
  digitalWrite(MOTRA,HIGH);
  digitalWrite(MOTRB,HIGH);
  digitalWrite(MOTREN,HIGH);

  analogWrite(MOTRPWM,255);
  analogWrite(MOTLPWM,255);

  delay(200);

  sensor();

  
}
