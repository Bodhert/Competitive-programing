#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define UNVISITED -1
#define MAXN 100005

vi g[MAXN];
vi grev[MAXN];
vi topo_sort;
int scc[MAXN];
int entran[MAXN];
bool seen[MAXN];

void dfs1(int u){
  seen[u] = true;
  for(int i = 0; i < g[u].size();++i){
    int v = g[u][i];
    if(!seen[v]) dfs1(v);
  }
  //cout << "fasd" << u << endl;
  topo_sort.push_back(u);
}

void dfs2(int u, int comp ){
  scc[u] = comp;
  for(int i = 0; i < grev[u].size(); ++i){
    int v = grev[u][i];
    if(scc[v] == -1) dfs2(v,comp);
  }
}

int find_scc(int n){
  
  for(int u = 0; u < n; ++u){
    for(int i = 0; i < g[u].size();++i){
      int v = g[u][i];
      grev[v].push_back(u);
    }
  }

  for(int i = 0; i < n; ++i)
    if(!seen[i]) dfs1(i);

  reverse(topo_sort.begin(),topo_sort.end());
  
  // for(int i = 0; i < topo_sort.size();++i){
  //   cout << topo_sort[i]  << ' ';
  // }
  // cout << endl;
  
  int comp = 0;

  for(int i = 0; i < n; ++i){
    int u = topo_sort[i];
    if(scc[u] == -1) dfs2(u,comp++);
  }

  // for(int i = 0; i < n;++i){
  //   cout << scc[i]  << ' ';
  // }
  //cout << endl;
  
  return comp;
}

int check(int nodes,int comp){
  for(int i = 0; i < nodes; ++i){
    int v = i;
    for(int j = 0; j < g[i].size(); ++j){
      int u = g[i][j];
      if(scc[v] != scc[u]) entran[scc[u]] += 1;
    }
  }

  int ans = 0;
  for(int i = 0; i < comp; ++i){
    if(entran[i] == 0) ans++; 
  }

  return ans;
}

int main(){
  int cases, nodes,con,con1,con2;

  cin >> cases;

  while(cases--){
    
    topo_sort.clear();
    for(int i = 0; i < MAXN; ++i){
      seen[i] = false;
      scc[i] = -1;
      g[i].clear();
      grev[i].clear();
      entran[i] = 0;
    }
    //limpiar contenedores
    
    cin >> nodes >> con;
    
    for(int i = 0; i < con; i++){
      cin >> con1 >> con2;
      g[con1-1].push_back(con2-1);
    }

    int comp = find_scc(nodes);

    int ans = check(nodes,comp);

    cout << ans << endl;
    
  }
  return 0;
}
