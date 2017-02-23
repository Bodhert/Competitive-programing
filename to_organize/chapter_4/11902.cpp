#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//const int MAXN = 105;
//int M[MAXN][MAXN];
vector < vector<int> > a;
int visited[105];


void dfs_1(int u){
  visited[u] = 2;
  for(int j = 0; j < a[u].size();j++){
    int v = a[u][j];
    if(visited[v] == 1) dfs_1(v);
  }
}

int main(){
  int T,N,D;
  cin >> T;
  while(T--){
    cin >> N;
    
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N;j++){
	cin >> D;
	if(D == 1)
	  a[i].push_back(j);
      }
    }

    for (int i = 0; i < 105; i++)
      visited[i] = 1;
    
  }
  return 0;  
}

