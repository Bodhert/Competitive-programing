using namespace std;
#include <bits/stdc++.h>

const int MAXN = 30;
vector <int> graph[MAXN];
int visited[MAXN];

void clear()
{
  for(int i = 0; i < MAXN; ++i)
  {
    graph[i].clear();
    visited[i] = -1;
  }
}

int dfs(int u)
{
  visited[u] = 1;
  for(int i = 0; i < graph[u].size(); ++i)
  {
    int next = graph[u][i];
    if(visited[next] == -1) dfs(next);
  }
  return 1;
}



int main()
{
  int t,node;
  char MaxNode;
  string Nodes;

  cin >> t;

  while(t--)
  {
    clear();//limpiar recipientes
    // cout << endl;
    cin >> MaxNode;
    // cout << MaxNode << endl;
    node = MaxNode - 'A';
    // cout << node << endl;
    getline(cin,Nodes);
    while(getline(cin,Nodes) && Nodes.size()!= 0)
    {
      int n1,n2;
      n1 = Nodes[0] - 'A';
      n2 = Nodes[1] - 'A';

      graph[n1].push_back(n2); graph[n2].push_back(n1);  // que pasara si pusheo algo 2 veces;
      // cout << n1 << " "  << n2 << endl;
    }

    int cont = 0;
    for(int i  = 0; i <= node; ++i)
    {
      if(visited[i] == -1) cont += dfs(i);  // contar cuantos estan conectados
    }
    
    if(t != 0) cout << cont << endl << endl;
    else cout << cont << endl;

  }

  return 0;
}
