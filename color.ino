#include <Servo.h>

#define R 48
#define G 49
#define B 50

void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}



void colorSense(){

  delay(1000);
  color();
 // Serial.println("RED");  
  Serial.println(red, DEC);  
  //Serial.println(" GREEN ");  
  Serial.println(green, DEC);  
  //Serial.println(" BLUE ");  
  Serial.println(blue, DEC);  

  if (red < blue && red < green)
  {  
      if (red <=10 && green <=10 && blue <=10){ 
     Serial.println("WHILE");   
  } else{
   Serial.println(" - (Red Color)");

   /////////////////////////////////


    digitalWrite(R,HIGH);
    digitalWrite(G,LOW);
    digitalWrite(B,LOW);
    turnTwoServos(ServoLs,ServoRs,120,60,30,1);
    delay(200);
    servoTurnDecrement(ServoL,170,33,7);
    servoTurnDecrement(ServoTray,82,50,7);
    delay(300);
    ServoTLid.write(120);
    delay(200);
    servoTurnIncrement(ServoTray,50,82,7);

     
    ServoTLid.write(30);
    
    
    

    
  }
}  
else if (blue < red && blue < green)   
  {  
   if (red <=10 && green <=10 && blue <= 10){
     Serial.println("WHILE");  
  }else {

      if (red < 25){
  
          Serial.println("board");
          digitalWrite(R,HIGH);
          digitalWrite(G,HIGH);
          digitalWrite(B,HIGH);
          turnTwoServos(ServoLs,ServoRs,120,60,30,1);
          delay(500);
          servoTurnDecrement(ServoL,170,33,7);
          
        
      }else{
     Serial.println(" - (Blue Color)");   
  
      
  
      turnTwoServos(ServoLs,ServoRs,120,60,30,1);
      delay(500);
      
      servoTurnDecrement(ServoL,170,33,7);
      delay(500);
      ServoTLid.write(120);
      
      delay(500);
      
      ServoTLid.write(30);
      
   
  
    }
    
    }
    
    }
  
  else if (green < red && green < blue)  
  {  
    if (red <= 10 && green <=10 && blue <= 10){
     Serial.println("WHILE");   
  } else{
   Serial.println(" - (Green Color)");  }


    digitalWrite(R,LOW);
    digitalWrite(G,HIGH);
    digitalWrite(B,LOW);

    turnTwoServos(ServoLs,ServoRs,120,60,30,1);
    delay(500);
    servoTurnDecrement(ServoL,170,33,7);
    servoTurnIncrement(ServoTray,82,124,7);
   
    ServoTLid.write(120);
    delay(100);
    servoTurnIncrement(ServoTray,124,82,7);
    
    ServoTLid.write(30);
  }  
  else{
  Serial.println();  
  }
}



 
