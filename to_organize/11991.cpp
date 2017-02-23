#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > a ; 

int main(){
  int n,m,elements,base,toSearch;
  while(cin >> n >> m){
     a.assign(1000005,vector<int>());
     
    for(int i = 1; i <= n; i++){
      cin >> elements;
      a[elements].push_back(i);
    }

   
    while(m--){
      cin >> base >> toSearch;
      if(base - 1  < a[toSearch].size())
	cout << a[toSearch][base - 1] << endl;
      else
	cout << '0' << endl;
    }

  }
  return 0;
}
