#include <bits/stdc++.h>

using namespace std;

struct edge {
  int start,end,weight;

  edge(int u, int v, int w){
    start = u; end = v; weight = w;
  }

  bool operator < (const edge &other) const{
    return weight < other.weight;
  }
};


const int MAXN = 200005;
vector <edge> edges;
int p[MAXN];

void cleanRecipes(){
  edges.clear();
  for(int i = 0; i < MAXN; ++i){
    p[i] = -1;
  }
  
}

int find(int u){
  if(p[u] == u) return u;
  return p[u] = find(p[u]);
}

void join(int u, int v){
  int a = find(u);
  int b = find(v);

  //cout << "int a: " << a  << " int b: " << b << endl; 
  if(a ==  b) return;
  
  p[a] = b;
}

void initialize(int n){
  for(int i = 0; i < n; ++i)
    p[i] = i;
}

int kruskal(int n){
  initialize(n);
  sort(edges.begin(),edges.end());

  int finalcost = 0;
  int aristasF = 0;

  for(int i = 0; i < edges.size() && aristasF < n; ++i){
    int u = edges[i].start;
    int v = edges[i].end;
    int w = edges[i].weight;
    //cout << "u: " <<u << " v:" << v << " w:" << w <<endl;
    if(find(u) != find(v)){
      finalcost += w;
      aristasF++;
      join(u,v);
    }
  }
  return finalcost;
}



int main(){
  int m,n,x,y,z,actualcost,finalcost;
 
  while(scanf("%i %i", &m,&n) && (m || n)){
    
    cleanRecipes();
    actualcost = 0;
    
    for(int i = 0; i < n; ++i){
      scanf("%i %i %i", &x,&y,&z);
      actualcost += z;
      edge in = edge(x,y,z);
      edges.push_back(in);
    }

    finalcost = kruskal(m);
    //cout << "costo final " <<finalcost << " costo actual: "  << actualcost <<endl;
    if(finalcost < actualcost)
      printf("%i\n", actualcost - finalcost);
    else
      printf("%i\n",0);
  }
  return 0;
}
