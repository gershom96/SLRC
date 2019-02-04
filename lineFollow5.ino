void lineFollow5(){
    digitalWrite(MOTLA,HIGH);
  digitalWrite(MOTLB,LOW);
  digitalWrite(MOTLEN,HIGH);
  
  digitalWrite(MOTRA,HIGH);
  digitalWrite(MOTRB,LOW);
  digitalWrite(MOTREN,HIGH);

   sensor();
   

    error=pos2;
    PID=Kp*(error)+Kd*(error-last_error)+Ki*(tot_error);
  
    analogWrite(MOTRPWM,constrain(ref_speed+int(PID),0,255));
    analogWrite(MOTLPWM,constrain(ref_speed-int(PID),0,255));
  
    last_error=error;
    tot_error+=error;
  }
