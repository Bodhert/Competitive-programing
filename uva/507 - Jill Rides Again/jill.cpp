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
      else if(sum == ans) index = i;
    }
    
    //ingeniarmelas para sacar el minimo  y el maximo actual de path y desps su correspondientes posiciones
    //    cout << ans << endl;
    if(ans == 0) cout << "Route " << route++ << " has no nice parts" << endl;
    else{
      int index2;
      for(int i = index; i > 0 && actualSum[i] > 0; i--){
	index2 = i;
      }
      //hacer un for y le sumo el path a ans y la suma que me de mas alto es otro indice ,
      cout << "The nicest part of route " << route++ << " is between stops " << index2 << " and " << index+1 << endl;
    }
    
    
    
    
  }
  
  
  return 0;
}
