using namespace std;
#include <bits/stdc++.h>

const int MAXN = 105;

vector <int> adj[MAXN];
int visited[MAXN];

void printGraph(int n)
{
  for(int i = 0; i < n; ++i)
  {
    cout << " el nodo " << i << " va a: ";
    for(int j = 0; j < adj[i].size();++j)
    {
      cout  << adj[i][j] << " ";
    }
    cout << endl;
  }
}

void printVisited(int n)
{
  for(int i = 0; i < n; ++i){
    cout << i << " estado " << visited[i];
    cout << endl;
  }
}

void clean2(int n)
{
  for(int i = 0; i < n; ++i)
  {
    if(visited[i] >= 0) visited[i] = 0;
  }
}

void clean1()
{
  for(int i = 0; i < MAXN; ++i)
  {
    adj[i].clear();
    visited[i] = -1;
  }
}

void dfs2(int u, int x)  //desconectar x sin borrarlo
{
  visited[u] = 1; // se estan visitando aunque estan desconectados de 0?

  for(int i = 0; i < adj[u].size(); ++i)
  {
    int next = adj[u][i];
    if(visited[next] == 0 && next != x) dfs2(next,x);
  }
}

void dfs1(int u)
{
  visited[u] = 0;
  for(int i = 0; i < adj[u].size(); ++i)
  {
    int next = adj[u][i];
    if(visited[next] == -1) dfs1(next);
  }
}

int main()
{
  int tc,n,v;
  int cont = 0;
  cin >> tc;
  while(tc--)
  {
    clean1();
    cin >> n;
    for(int i = 0; i < n; ++i)  // estoy guardando asi como asi, estoy guardando mal
    {
      for(int j = 0; j < n; ++j)
      {
        cin >> v;
        if(v) adj[i].push_back(j);
      }
    }

    // printGraph(n);


    dfs1(0);

    cout << "Case " << ++cont << ":" << endl;

    string separator = "";
    for(int j = 0; j < (2*n)+1; ++j)
    {
      if(j == 0 || j == 2*n) separator += "+";
      else separator += "-";
    }
    // printVisited(n);

    cout << separator << endl;
    for(int i = 0; i < n; ++i)
    {
        if(visited[i] != -1) cout << "|Y";
        else cout << "|N";
    }

    cout << "|"<< endl;

    for(int i = 1; i < n; ++i)
    {
      clean2(n);
      if(visited[i] != -1)
      {
        cout << separator << endl;
        dfs2(0,i);
        for(int j = 0; j < n; ++j)
        {
          // a si mismo
          if(j == 0 || visited[j] == 1 || visited[j] == -1) cout << "|N";
          // a si mismo
          else if(visited[j] == 0 || j == i) cout << "|Y";
        }
        cout << "|" << endl;
      }
      else
      {
        cout << separator << endl;
        for(int j = 0; j < n; ++j)
        {
          cout << "|N";
        }
        cout << "|" << endl;
      }
      // printVisited(n);
      // for(int j = 0; j < n; ++j) // aca esta el error en la j == 0
      // {
        // if(j == 0 || visited[j] == -1 ) cout << "|N";
        // else if(j == i && visited[j] != -1) cout << "|Y";
        // else if() cout << "|N";
        // if(visited[j] == 0 || visited[j] == -1 || j == 0) cout << "|N";
        // else cout << "|Y";
      // }

      // cout << "|" << endl;
      // cout << "Nodo: " << i << " estado visitado " << endl;
      // printVisited(n);
    }

    cout << separator << endl;
  }
  return 0;
}
