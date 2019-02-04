void blink(){
  for(int i = 0; i<2; i++){
    sr.setAllHigh(); // set all pins HIGH
    delay(1000);
    sr.setAllLow(); // set all pins LOW
    delay(1000);
  }
}
