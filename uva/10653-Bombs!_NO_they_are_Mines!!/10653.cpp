#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1005;
int M[MAXN][MAXN];
int d[MAXN];

int main(){
  int R,C, rows,row,bombs ,bomb , acum ;
  for(int i = 0; i < MAXN; i++){
    for(int j = 0; j < MAXN; j++){
      M[i][j] = 0;
    }
  }
  
  while(cin >> R >> C && R!= 0 && C!=0){
    cin >> rows;
    while(rows--){
      cin >> row;
      cin >> bombs;
      while(bombs--){
	acum += bombs;
	cin >> bomb;
	M[row][bomb] = 1;
      }
    }
    int Srow,Scol,Erow,Ecol;
    cin >> Srow >> Scol >> Erow >> Ecol;

    for(int i = 0; i < acum; i++) d[i] = -1;

    queue <int> q;
    q.push(Srow); q.push(Scol);
    d[Srow] = d[Scol] = 1;
    while(!q.empty()){
      int cur = q.front();q.pop();
      // for(int i = 0; i < ){

      // }
    }
  }

   for(int i = 0; i < R; i++){
    for(int j = 0; j < R; j++){
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
 
  
  
  return 0;
}
