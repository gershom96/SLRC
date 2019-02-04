void lineFollow4(){

 
  digitalWrite(MOTLA,HIGH);
  digitalWrite(MOTLB,LOW);
  digitalWrite(MOTLEN,HIGH);
  
  digitalWrite(MOTRA,HIGH);
  digitalWrite(MOTRB,LOW);
  digitalWrite(MOTREN,HIGH);
 
  sensor(); // line sensors readings
  
  
  if(sum2>6 && pos2>-0.5 && pos2<0.5 ){
    
    digitalWrite(R,HIGH);
    digitalWrite(G,LOW);
    digitalWrite(B,LOW);
    /*while(sum<=6){
      lineFollow2();
    }*/
    inchFront();
    brakes();
    sensor();

    /************************ identifying state boxes **************/
    if(sum2>7 && sum>7 && pos2==0 && pos ==0){
      
      
      delay(1000);
      //ServoTray.write(180);
       
       brakes();
      RState+=1;
    }
 /*********************left turn (+ junction)*****************/
    else{

        if(String(shortPath[dCount])==String(5)){
          while(pos2>=-2.5){
            antiClk();
           }
           
           while(pos2<-0.5){
            antiClk();
           }
           brakes(); 
       }else if(String(shortPath[dCount])==String(6)){

          while(pos2 <=2.5){
              clk();
          }while(pos2>-0.5){
            clk();
           }
           brakes(); 
       }
        
    }
    
  }else if(sum2>4 && pos2<0){
    
    
    /*while(sum<=4){
      lineFollow2();
    }*/
    inchFront();
    brakes();
    
    if(sum2>7 && sum>7 && pos2==0 && pos==0){
      
      brakes();
      RState+=1;
    }
/*------------------------- left turn ----------------------- (-| junction)*/
   
    else{

      if(String(shortPath[dCount])==String(5)){
          while(pos2>=-2.5){
            antiClk();
           }
           
           while(pos2<-0.5){
            antiClk();
           }
           brakes(); 
       }else if(String(shortPath[dCount])==String(6)){

          while(pos2 <=2.5){
              clk();
          }while(pos2>-0.5){
            clk();
           }
           brakes(); 
       }
       
      }
    
  /**************************right turn *******************(;- junction)*****/  
  
  }else if(sum2>4 && pos2>0){
    
      fwrd(); //change value of delay if function is ublic
      if(sum2<6 && pos2>0){
      
      inchFront();
      brakes();
      /************************ identifying state boxes **************/
      if(sum2>7 && sum>7 && pos2==0 && pos ==0){
        
        brakes();
        RState+=1;
         
      }else if(sum2==0){
        //brakes();
        pos2=+1;
        while( pos2>0){
        clk();
        }
        brakes();
    }else{
      
      if(String(shortPath[dCount])==String(5)){
          while(pos2>=-2.5){
            antiClk();
           }
           
           while(pos2<-0.5){
            antiClk();
           }
           brakes(); 
       }else if(String(shortPath[dCount])==String(6)){

          while(pos2 <=2.5){
              clk();
          }while(pos2>-0.5){
            clk();
           }
           brakes(); 
       }
      
    }
    
  }
  
  }else{
    digitalWrite(R,LOW);
    digitalWrite(G,LOW);
    digitalWrite(B,LOW);
    error=pos2;
    PID=Kp*(error)+Kd*(error-last_error)+Ki*(tot_error);
  
    analogWrite(MOTRPWM,constrain(ref_speed+int(PID),0,255));
    analogWrite(MOTLPWM,constrain(ref_speed-int(PID),0,255));
  
    last_error=error;
    tot_error+=error;
  }
 
  
}
