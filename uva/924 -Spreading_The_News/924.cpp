//spreading the news;
// sin resolver
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define INF 1000000000

const int MAXN = 2505;
vector <int> adj[MAXN];
int boom[MAXN];



int main(){
  int E,N,A,T,S;
  cin >> E;
  for(int j = 0; j < E; j++){
    cin >> N;
    for(int i = 0; i < N; i++){
      cin >> A;
      adj[j].push_back(A);
      // adj[a].push_back(j);
    }
  }
  
  cin >> T;

  while(T--){
    cin >> S;
    for(int i = 0; i < MAXN; i++) boom[i] = -1;
    queue <int> q;
    q.push(S);
    boom[S] = 0;
    while(q.size() > 0){
      int cur = q.front(); q.pop();
      for(int i = 0 ; i < adj[cur].size(); i++){
	int next = adj[cur][i];
	if(boom[next] == -1){
	  boom[next] = boom[cur] + 1;
	  q.push(next);
	}
      }
    }
    if(!adj[S].size()){
      cout << "0\n";
      continue;
    }

    int maxl = 0, maxV =-INF;
    for(int i = 0; i < E; i++){
      if(maxV < boom[i]){
	maxV = boom[i];
	maxl = i;
      }
    }
    cout << maxV << " " << maxl << endl;
  }
  return 0;
}

