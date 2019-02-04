void lineFollow2(){  
  
     digitalWrite(R,HIGH);
    digitalWrite(G,HIGH);
    digitalWrite(B,HIGH);
    
  digitalWrite(MOTLA,HIGH);
  digitalWrite(MOTLB,LOW);
  digitalWrite(MOTLEN,HIGH);
  
  digitalWrite(MOTRA,HIGH);
  digitalWrite(MOTRB,LOW);
  digitalWrite(MOTREN,HIGH);
  
  sensor();
  
  error=pos;
  PID=Kp*(error)+Kd*(error-last_error)+Ki*(tot_error);

    
  Serial.println(pos);

  analogWrite(MOTRPWM,constrain(ref_speed+int(PID),0,255));
  analogWrite(MOTLPWM,constrain(ref_speed-int(PID),0,255));

  last_error=error;
  tot_error+=error;

 
}
