#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int b, s, in, identifier = 0;
  vector <int> path;

  cin >> b;

  while(b--){
    path.clear();
    cin >> s;
    s--;
    
    for(int i = 0; i < s; ++i){
      cin >> in;
      path.push_back(in);
    }

    int results[path.size()];

    int sum = 0; int ans = 0; int index = -1;
    
    for(int j = 0; j < path.size(); ++j){
      sum += path[j];
      ans = max(ans,sum);
      results[j] = sum;
      if(sum < 0) sum = 0;
      else if(sum == ans ) {
	index = j; // j+1
	// como saco el primer indice???
	// idea , cojo el ultimo que no de negativo , es decir
	// saco el ultimo indice, y me devuelvo a partir de este hasta
	// que la suma sea < 0, para esto es necesario guardar la sumas
	// de lo que cada uno me este arrojando en cada poscicion y rreco
	// rro al revez de este
      }
    }

    //es posible que no este reiniciendo alguna variable
    
    if(sum == 0) cout << "Route " << ++identifier << " has no nice parts" << endl;
    else {
      int i = index;
      while(results[i] >= 0){
	i--;
      }
      i += 2;
      index += 2;
      cout << "The nicest part of route " << ++identifier << " is between stops " << i << " and " << index << endl;
    }
  }
  
  return 0;
}
