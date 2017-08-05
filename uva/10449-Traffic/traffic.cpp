#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int MAXN = 205; // cambiar a 205
const int INF = 1000000000;

vector<ii> graph[MAXN];
int dist[MAXN];
int busyness[MAXN];

bool negative[MAXN];
bool negativePath[MAXN];

void bfs(int source) //finding the paths with negative cicle
{
    queue<int> q; q.push(source);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int i = 0; i < graph[cur].size(); ++i)
        {
            int next = graph[cur][i].first;
            if(negativePath[next] == 0)
            {
                negativePath[next] = 1;
                q.push(next);
            }
        }
    }
}

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

    for(int u =  0; u < nodes; ++u)
        {
            for(int j = 0; j < graph[u].size(); ++j )
            {
                int curNode = graph[u][j].first;
                int distance = graph[u][j].second;                
                if(dist[curNode] > dist[u] + distance) negative[curNode] = 1;
            }
        }

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

    freopen("in", "r", stdin); // debug purposes
    string in1;
    int juntions, roads, busynessNum, juntion1,juntion2 , queries, querie, set = 1;

    while( getline(cin, in1));
    {
        cout <<  in1 << endl;
        stringstream ss(in1);
        ss >> juntions;
        clean();
        for(int i = 0 ; i < juntions; ++i)
        {
            ss >> busynessNum;
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


        for(int i = 0; i < juntions; ++i)
        {
            if(negative[i] && !negativePath[i])
            {
                bfs(i);
            }
        }

        cin >> queries;

        cout << "Set #" << set << endl;
        set++;

        for(int i = 0; i < queries; ++i)
        {
            cin >> querie;
            querie--;
            int earn = pow(busyness[querie] - busyness[0],3);
            negativePath[querie] || earn < 3 ? cout << "?" << endl : cout << earn << endl;
        }
    }
    return 0;
}