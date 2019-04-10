#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MAXN = 50010; 

int parents[MAXN];

vi graph[MAXN];
vi reversedGraph[MAXN];
vii SimpleEdges;

int scc[MAXN];
bool seen[MAXN];
vi toposort;

int find(int u)
{
    if (parents[u] == u)
        return u;
    return parents[u] = find(parents[u]);
}

void join(int u, int v)
{
    int a = find(u);
    int b = find(v);
    if (a == b)
        return;
    parents[a] = b;
}

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
        int p = find(i);
        if (!seen[p])
            dfs1(p);
    }

    reverse(toposort.begin(), toposort.end());

    int comp = 0;
    for (int i = 0; i < toposort.size() && comp <=1; ++i)
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
    SimpleEdges.clear();
    for (int i = 0; i < nodes; ++i)
    {
        graph[i].clear();
        reversedGraph[i].clear();
        seen[i] = false;
        scc[i] = -1;
        parents[i] = i;
    }
}

int main()
{
    //freopen("in", "r", stdin); // for debug purposes
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
                SimpleEdges.push_back(pii(u, v));
            }
            else
            {
                cin >> u;
                u--;
                for (int i = 1; i < procedures; ++i)
                {
                    cin >> v;
                    v--;
                    join(u, v);
                }
            }
        }

        for (pii simpleEdge : SimpleEdges)
        {
            int u = find(simpleEdge.first);
            int v = find(simpleEdge.second);
            graph[u].push_back(v);
            reversedGraph[v].push_back(u);
        }

        int ans = kosaraju(nodes);
        ans == 1 ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
