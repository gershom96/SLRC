void clk(){
  
  digitalWrite(MOTRA,HIGH);
  digitalWrite(MOTRB,LOW);
  digitalWrite(MOTLEN,HIGH);
  
  digitalWrite(MOTLA,LOW);
  digitalWrite(MOTLB,HIGH);
  digitalWrite(MOTREN,HIGH);
  
  analogWrite(MOTRPWM,120);
  analogWrite(MOTLPWM,120);

    sensor();
}
