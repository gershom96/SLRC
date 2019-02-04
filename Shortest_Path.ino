  QList<int> reversePath(QList<int> path){

  QList<int> reverse_path;
  
  for (int i=0;i<path.size();i++){
    
    reverse_path.push_back(path[path.size()-1-i]);
    
    }

  return reverse_path;
  
  }

String shortestPath(QList<int> path){
  
  /*

    0 - North
    1 - East
    2 - South
    3 - West 
  
  */
  
  int isTrue = 0;

  while (true){


    isTrue = 1;    
    
    for (int i=0; i< path.size()-1; i++){
      
        if (path[i] == 0 && path[i+1] == 2){
          
          path.clear(i);
          path.clear(i);

          //Serial.println("found");

          isTrue = 0;
          
          }

        if (path[i] == 2 && path[i+1] == 0){
          
          path.clear(i);
          path.clear(i);

          //Serial.println("found");

          isTrue = 0;
          
          }

        if (path[i] == 1 && path[i+1] == 3){
          
          path.clear(i);
          path.clear(i);

          //Serial.println("found");

          isTrue = 0;
          
          }


        if (path[i] == 3 && path[i+1] == 1){
          
          path.clear(i);
          path.clear(i);

          //Serial.println("found");

          isTrue = 0;
          
          }
      
      }

    if (isTrue == 1){
      
      break;
      
      }
    
    
    
    }

  QList<int> final_list;

  /*

    Left 5
    Right 6
    Straight 7  
  
  */

  int prev_state = 0;
  int state;

  for (int i=0; i<path.size(); i++){
    
    state = path[i];

    if (state - prev_state > 0 ){
      
      final_list.push_back(6);
      }

    else if(state - prev_state < 0 ){
      
      final_list.push_back(5);
      }

    else if(state - prev_state == 0 ){
      
      final_list.push_back(7);
      }

    prev_state = state;
    
    }

   QList<int> reverse_path_final = reversePath(final_list);

   for (int i=0; i< reverse_path_final.size(); i++){
    
    if (reverse_path_final[i] == 5 ){
      
        reverse_path_final[i] = 6;
      }


    else if (reverse_path_final[i] == 6 ){
      
        reverse_path_final[i] = 5;
      }
      
    }

   String ans = ""; 

   for (int i=0;i<reverse_path_final.size();i++){

      ans = ans + String(reverse_path_final.get(i));
    
    }

      

  //return  reverse_path_final;
  //Serial.print(ans);
  return ans;
  
  
  }
  
