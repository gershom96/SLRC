void sensor(){

   sum=0;
  w_sum=0;
  sum2=0;
  w_sum2=0;
  
  for(int i=0;i<=7;i++){

    //for the Back IR
    
    if(digitalRead(analog_pins[i])==LOW){
       sensorValues[i]=1;
    }else{
       sensorValues[i]=0;
    }

    //for the Front IR

    if(digitalRead(sensor2Pins[i])==LOW){
       sensor2Values[i]=1;
    }else{
       sensor2Values[i]=0;
    }
   
    sum+=sensorValues[i];
    sum2+=sensor2Values[i];
    
    w_sum+=(i+1)*sensorValues[i];
    w_sum2+=(i+1)*sensor2Values[i];
    
    Serial.print(sensorValues[i]);
    Serial.print('\t'); 
    if(sum!=0){
 
      pos=(w_sum/sum-4.5);
      
    }if(sum2!=0){

      pos2=(w_sum2/sum2-4.5);
      
    }
  }
  
  Serial.println(pos);
}
