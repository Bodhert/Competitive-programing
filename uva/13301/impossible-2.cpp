#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAXN = 50005; // change

vi graph[MAXN];
vi reversedGraph[MAXN];

int scc[MAXN];
bool seen[MAXN];
vi toposort;


void dfs2(int u, int comp)
{
    scc[u] = comp;
    for (int i = 0; i < reversedGraph[u].size(); ++i)
    {
        int v = reversedGraph[u][i];
        if (scc[v] == -1)
            dfs2(v, comp);
    }
}

void dfs1(int u)
{
    seen[u] = true;
    for (int i = 0; i < graph[u].size(); ++i)
    {
        int v = graph[u][i];
        if (!seen[v])
            dfs1(v);
    }

    toposort.push_back(u);
}

int kosaraju(int n)
{

    for (int i = 0; i < n; ++i)
    {
        if (!seen[i])
            dfs1(i);
    }

    reverse(toposort.begin(), toposort.end());

    int comp = 0;
    for (int i = 0; i < n; ++i)
    {
        int u = toposort[i];
        if (scc[u] == -1)
            dfs2(u, comp++);
    }

    return comp;
}

void initialize(int nodes)
{
    toposort.clear();
    for (int i = 0; i < nodes; ++i)
    {
        graph[i].clear();
        reversedGraph[i].clear();
        seen[i] = false;
        scc[i] = -1;
    }
}

int main()
{
    // freopen("in", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges, procedures, u, v;
    while (cin >> nodes >> edges)
    {
        initialize(nodes);

        for (int i = 0; i < edges; ++i)
        {
            cin >> procedures;
            if (procedures == 1)
            {
                cin >> u >> v;
                u--;
                v--;
                graph[u].push_back(v);
                reversedGraph[v].push_back(u);
            }
            else
            {
                cin >> u;
                u--;
                for (int i = 1; i < procedures; ++i)
                {
                    cin >> v;
                    v--;
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                    
                    reversedGraph[u].push_back(v);
                    reversedGraph[v].push_back(u);
                }
            }
        }

        int ans = kosaraju(nodes);
        ans == 1 ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
