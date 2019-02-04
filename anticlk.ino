void antiClk(){

  sensor();
  digitalWrite(MOTLA,HIGH);
  digitalWrite(MOTLB,LOW);
  digitalWrite(MOTLEN,HIGH);
  
  digitalWrite(MOTRA,LOW);
  digitalWrite(MOTRB,HIGH);
  digitalWrite(MOTREN,HIGH);
  
  analogWrite(MOTRPWM,120);
  analogWrite(MOTLPWM,120);


}
