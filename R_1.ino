void R_1(){

  if(RState == 0){
    
    lineFollow();
    
  }else if(RState ==1){

    lineFollow3();
    
  }else if(RState ==2){
       
    lineFollow4();
    
  }else if(RState==3){

    for(int i=0;i<=10;i++){
      inchFront();
    }
    lineFollow5(); //dashed line follow
      
  }
  
}
