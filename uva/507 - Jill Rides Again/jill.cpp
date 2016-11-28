#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int cases,route = 1,stops,nicennes;
  vector <int> path;
  vector <int> actualSum;

  //voy a manejar todo indice 1
  cin >> cases;
  while(cases--){
    cin >> stops;
    path.assign(stops,0); actualSum.assign(stops,0);
    
    for(int i = 1; i < stops; i++){
      cin >> nicennes;
      path[i] = nicennes;
    }

    //kadanes algorithm
    int sum = 0, ans = 0, index = 0;
    for(int i = 1; i < stops; i++){
      sum += path[i];
      ans = max(ans,sum);
      actualSum[i] = sum;
      if(sum < 0) sum = 0;
      else if(sum == ans) index = i+1;
    }
    //ingeniarmelas para sacar el minimo  y el maximo actual de path y desps su correspondientes posiciones

    if(ans == 0) cout << "Route " << route++ << " has no nice parts" << endl;
    else{
      //hacer un for y le sumo el path a ans y la suma que me de mas alto es otro indice,
      
      cout << "The nicest part of route " << route++ << " is between stops " << "?" << " and " << index << endl;
    }
    
    
    
    
  }
  
  
  return 0;
}
