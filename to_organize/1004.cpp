#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAXN = 206;
vector <int> A[MAXN];
int color[MAXN];

bool bfs(int s){
  queue <int> q;
  q.push(s);
  color[s] = 0;
  while(q.size() > 0 ){
    int u  = q.front(); q.pop();
    for(int i = 0; i < A[u].size(); i++){
      int v = A[u][i];
      if(color[v] == color[u]) return false;

      if(color[v] == -1){
	color[v] = 1 - color[u];
	q.push(v);
      }
    }
  }
  return true;
}

int main(){
  int n,l,u,v;
  while(cin >> n && n != 0){
    for(int i = 0; i < n; i++){
      A[i].clear();
      color[i] = -1;
    }
    cin >> l;
    for(int i = 0; i < l; i++){
      cin >> u >> v;
      A[u].push_back(v);
      A[v].push_back(u);
    }
    if(bfs(0)) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
  }
  return 0;
}
