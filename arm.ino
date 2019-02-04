

/**************************************************** copy area *****************************************************************/

void servoTurnIncrement(Servo servo,int start_deg,int end_deg,int delay_){
  
  for (int i = start_deg;i<= end_deg;i++){

    servo.write(i);
    delay(delay_);   
    
    }
  
  }

void servoTurnDecrement(Servo servo,int start_deg,int end_deg,int delay_){
  
  for (int i = start_deg;i>= end_deg;i--){

    servo.write(i);
    delay(delay_);   
    
    }
  
  }


void turnTwoServos(Servo servo1,Servo servo2,int start_deg1,int start_deg2,int deg,int delay_){

  int turn_servo_1 = start_deg1;
  int turn_servo_2 = start_deg2;
  
  for (int i = 0;i <= deg;i++){

    turn_servo_1 = turn_servo_1 -1;
    turn_servo_2 = turn_servo_2 +1;
    servo1.write(turn_servo_1);
    servo2.write(turn_servo_2);
    delay(delay_);   
    
    }
  
  }


/**************************************************** copy area *****************************************************************/

Servo servo1;  
Servo servo2;
