
void Move(){
  servoTurnIncrement(ServoL,33,170,7);
  delay(2000);
  turnTwoServos(ServoRs,ServoLs,90,90,30,1);
  
  delay(1000);
  colorSense();
  
}
