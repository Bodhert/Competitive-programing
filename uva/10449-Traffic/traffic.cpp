#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int MAXN = 205; // cambiar a 205
const int INF = 1000000000;

vector<ii> graph[MAXN];
int dist[MAXN];
int busyness[MAXN];
int negative[MAXN];
int negativePath[MAXN];

void ModifiedbellmanFord(int nodes, int source)
{
    dist[source] = 0;
    for(int i =  0; i < nodes - 1; ++i)
    {
        for(int u =  0; u < nodes; ++u)
        {
            for(int j = 0; j < graph[u].size(); ++j )
            {
                int curNode = graph[u][j].first;
                int distance = graph[u][j].second; 
                dist[curNode] = min(dist[curNode], dist[u] + distance );
            }
        }
    }


      bool hasNegativeCycle = false;
  for (int u = 0; u < nodes; u++)                          // one more pass to check
    for (int j = 0; j < (int)graph[u].size(); j++) {
      ii v = graph[u][j];
      if (dist[v.first] > dist[u] + v.second)                 // should be false
        hasNegativeCycle = true;     // but if true, then negative cycle exists!
    }
    
  printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");
}

void clean()
{

    for (int i = 0 ; i < MAXN; ++i)
    {
        graph[i].clear();
        dist[i] = INF;
        negative[i] = 0;
        negativePath[i] = 0;
    }
}
 //recordar que estoy trabajando base 0 y el problema es base 1
int main()
{

    //freopen("in", "r", stdin); // debug purposes
    int juntions, roads, busynessNum, juntion1,juntion2 , queries, querie, set = 1;

    while(cin >> juntions)
    {
        clean();        
        for(int i = 0 ; i < juntions; ++i)
        {
            cin >> busynessNum;
            busyness[i] = busynessNum;
        }

        cin >> roads;

        for(int i = 0; i < roads; ++i)
        {
            cin >> juntion1 >> juntion2;
            juntion1--; juntion2--;
            int distance = pow(busyness[juntion2] - busyness[juntion1],3);
            graph[juntion1].push_back(ii(juntion2,distance));
        }

        ModifiedbellmanFord(juntions , 0);


        cin >> queries;

        cout << "Set #" << set << endl;
        set++;

        for(int i = 0; i < queries; ++i)
        {
            cin >> querie;
            querie--;
            //negativePath[querie] || dist[querie] < 3 || dist[querie] == INF ? 
            //    cout << "?" << endl : cout << dist[querie] << endl;
            cout << dist[querie] << endl;
        }
    }

    return 0;
}