void lineFollow(){

  digitalWrite(MOTLA,HIGH);
  digitalWrite(MOTLB,LOW);
  digitalWrite(MOTLEN,HIGH);
  
  digitalWrite(MOTRA,HIGH);
  digitalWrite(MOTRB,LOW);
  digitalWrite(MOTREN,HIGH);
 
  sensor(); // line sensors readings
  
  /****************dead ends *********************/
  
  
  if(sum2==0){
  
    
   init_State=(init_State-2)%4;
   path.push_back(init_State);
  //BTserial.print((init_State));
       
   
   brakes();
   //buzzerSound(2);
   Back();
   brakes();
   pos2=-1;
   Move();
   while(pos2<=-0.5){
    antiClk();
    }
    brakes();
  
        
  }else if(sum2>6 && pos2>-0.5 && pos2<0.5 ){
    
    
    /*while(sum<=6){
      lineFollow2();
    }*/
    inchFront();
    brakes();
    sensor();
    

    /************************ identifying state boxes **************/
    if(sum2>7 && sum>7 && pos2==0 && pos ==0){

        //buzzerSound(3);
      
       while(pos2>=-2.5){
        antiClk();
       }
       
       while(pos2<-0.5){
        antiClk();
       }
       brakes();
      RState+=1;
    }
 /*********************left turn (+ junction)*****************/
    else if(sum2>0){
      
       init_State=(init_State-1)%4;
       path.push_back(init_State);
      // BTserial.print((init_State));
       //buzzerSound(2);
         
        while(pos2>=-2.5){
        antiClk();
       }
       
       while(pos2<-0.5){
        antiClk();
       }
       brakes();
 /**************************left turn(T junction) ************************/
 
    }else{
      
    init_State=(init_State-1)%4;
    path.push_back(init_State);
    //BTserial.print((init_State));

    //buzzerSound(2);
    
    pos2=-1;
    while( pos2<0 ){
      antiClk();
      }
      brakes();
    }
    
  }else if(sum2>4 && pos2<0){
    
    
    /*while(sum<=4){
      lineFollow2();
    }*/
    inchFront();
    brakes();
    
    if(sum2>7 && sum>7 && pos2==0 && pos==0){
      
    //  ServoTray.write(180);
       while(pos2>=-2.5){
        antiClk();
       }
       
       while(pos2<-0.5){
        antiClk();
       }
       brakes();
      RState+=1;
    }
/*------------------------- left turn ----------------------- (-| junction)*/
   
    else if(sum2>0){    /////////////////  
        
          init_State=(init_State-1)%4 ;   
          path.push_back(init_State);
          //BTserial.print((init_State));

          //buzzerSound(2);
            
          while(pos2>=-2.5){
          antiClk();
         }
         
         while(pos2<-0.5){
          antiClk();
         }
         brakes();

         
   /**************************left turn *******************(-; junction)*****/
      }else{

        //buzzerSound(1);
      pos2=-1;
      while( pos2<0){
        antiClk();
        }
        brakes();
      }
    
  /**************************right turn *******************(;- junction)*****/  
  
  }else if(sum2>4 && pos2>0){
     

      
    fwrd(); //change value of delay if function is ublic
    if(sum2<6 && pos2>0){
      
   
      
     /* while(sum<=4){
        lineFollow2();
      }*/
      inchFront();
      brakes();
      /************************ identifying state boxes **************/
      if(sum2>7 && sum>7 && pos2==0 && pos ==0){
        
    
         while(pos2>-2.5){
        antiClk();
       }
       
       while(pos2<-0.5){
        antiClk();
       }
       brakes();
        RState+=1; 
      }
      else if(sum2==0){

         //buzzerSound(1);
        //brakes();
        pos2=+1;
        while( pos2>0){
        clk();
        }
        brakes();
    }else{

       //buzzerSound(2);
      init_State=(init_State)%4;
     path.push_back(init_State);
     //BTserial.print((init_State));
      
    }
    
  }
  
  }
  else{
    
    error=pos2;
    PID=Kp*(error)+Kd*(error-last_error)+Ki*(tot_error);
  
    analogWrite(MOTRPWM,constrain(ref_speed+int(PID),0,255));
    analogWrite(MOTLPWM,constrain(ref_speed-int(PID),0,255));
  
    last_error=error;
    tot_error+=error;
  }
 
  
}
