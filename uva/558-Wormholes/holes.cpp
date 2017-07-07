#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

const int MAXN = 1005;
const int INF = 1000000000;
vector <ii> graph[MAXN];
int distances[MAXN];

void clean()
{
    for(int i = 0 ; i < MAXN; ++i) 
    {
        graph[i].clear();
        distances[i] = INF;
    }
}

void bellmanFord(int nodes, int source)
{
    distances[source] = 0;
    for(int i =  0; i < nodes - 1; ++i)
    {
        for(int u =  0; u < nodes; ++u)
        {
            for(int j = 0; j < graph[u].size(); ++j )
            {
                int curNode = graph[u][j].first;
                int curDistance = graph[u][j].second;                
                distances[curNode] = min(distances[curNode], distances[u] + curDistance );
            }
        }
    }
}

bool hasnegativecicle(int nodes)
{
    for(int u  = 0; u < nodes; ++u)
    {
        for(int j = 0; j < graph[u].size(); ++j)
        {
            int curNode = graph[u][j].first;
            int curDistance = graph[u][j].second; 
            if(distances[curNode] > distances[u] + curDistance) return true;
        }
    }

    return false;
}

int main()
{
    //freopen("in", "r", stdin); // debug purposes
    int cases, starts, wormholes , hole1,hole2, years;
    cin >> cases;
    while(cases--)
    {
        clean();
        cin >> starts >> wormholes;
        for(int i = 0; i < wormholes ; ++i)
        {
            cin >> hole1 >> hole2 >> years;
            graph[hole1].push_back(ii(hole2,years));
        }

        bellmanFord(starts,0);
        if(hasnegativecicle(starts)) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
    
    return 0;
}