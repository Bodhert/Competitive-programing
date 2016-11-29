#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main(){
  int cases,route = 1,stops,nicennes;
  vector <int> path;

  //voy a manejar todo indice 1
  cin >> cases;
  while(cases--){
    cin >> stops;
    path.assign(stops,0);
    
    for(int i = 1; i < stops; i++){
      cin >> nicennes;
      path[i] = nicennes;
    }

    //kadanes algorithm
    int sum = 0, maxi = 0, a = 0, b = 0 , c = 0;
    for(int j = 1; j < stops; j++){
      sum += path[j];
      if(sum > maxi || (sum == maxi && j - a > b - c) ){
	maxi = sum ;
	b = j;
	c = a;
      }
      if(sum < 0){
	sum = 0;
	a = j;
      }
     
    }
    
    if(maxi <=  0) cout << "Route " << route++ << " has no nice parts" << endl;
    else{
      cout << "The nicest part of route " << route++ << " is between stops " << c+1 <<" and "  << b+1 << endl;
    }
  
    
  }
  
  
  return 0;
}
