boolean deadends(){

   init_State=(init_State-2)%4;
   path.push_back(init_State);

   digitalWrite(R,LOW);
   digitalWrite(G,HIGH);
   digitalWrite(B,LOW);

   brakes();
   pos2=-1;
   while(pos2<=-1){
    antiClk();
    }
    brakes();
  
}
