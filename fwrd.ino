void fwrd(){

  digitalWrite(MOTLA,HIGH);
  digitalWrite(MOTLB,LOW);
  digitalWrite(MOTLEN,HIGH);
  
  digitalWrite(MOTRA,HIGH);
  digitalWrite(MOTRB,LOW);
  digitalWrite(MOTREN,HIGH);

  analogWrite(MOTRPWM,120);
  analogWrite(MOTLPWM,120);

  delay(60);   //120

  sensor();
  
}
