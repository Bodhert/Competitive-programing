#include <iostream>
#include <map>

using namespace std;

map<int,bool> mapa;

int main(){
  int n,m,cont,cd;
  while(cin >> n >> m && (m && n)){
    cont = 0;
    mapa.clear();
    for(int i = 0; i < n; i++){
      cin >> cd;
      mapa[cd] = true;
    }
    
    for(int i = 0; i < n; i++){
      cin >> cd;
      if(mapa.count(cd)) cont++;
    }

    cout << cont << endl;
  }
  return 0;
}
