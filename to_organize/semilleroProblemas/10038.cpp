#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int num[3005],abss[3005];

int main(){
  int n, val;
  while(cin >> n ){
    
    
    for(int i = 0; i < n; i++){
      cin >> val;
      num[i] = val;
    }
    
    for(int j = 0; j < n - 1 ; j++){
      abss[j] = abs(num[j+1] - num[j]);
    }

    sort(abss ,abss + n-1);

    bool jolly = true;
     for(int i = 0; i < n - 1 ; i++){
       if(abss[i] != i + 1){
	 jolly = false;
	 break;
       }
     }

     if(jolly) cout << "Jolly" << endl;
     else cout << "Not jolly" << endl;
    
  }
}
