#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
const int minimo = numeric_limits<int>::max();
const int maximo = numeric_limits<int>::max() * -1;

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

      //cout << "imprimiendo la sumas actuales: " << endl;
      //cout << minimo << " " << maximo << endl;
      //el problema esta en los desempates, creo que lo puedo hacer linean dentro de kadanes
      // for(int i = 0; i < actualSum.size(); ++i){
      // 	cout << actualSum[i] << " ";
      // }

      //cout << endl;
      
      int index2,index3 , dif = maximo ;
      for(int i = 1; i <= actualSum.size(); ++i){
	if(actualSum[i] == ans){
	  int tempIndex2 = i, tempIndex3;
   
	  for(int j = i; j >= 1 && actualSum[j] >= 0; j--){
	    tempIndex3 = j;
	  }

	  if(tempIndex2 - tempIndex3 > dif){
	    dif = tempIndex2 -tempIndex3;
	    index2 = tempIndex2;
	    index3 = tempIndex3;
	  }
	  
	}
      }
      
      //hacer un for y le sumo el path a ans y la suma que me de mas alto es otro indice ,
      cout << "The nicest part of route " << route++ << " is between stops " << index3 << " and " << index2+1 << endl;
    }
    
    
    
    
  }
  
  
  return 0;
}
