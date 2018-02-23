/*
ID: alejand24
TASK: wormhole
LANG: C++11
*/

// this is not all came to me , i was doing something wrong with the comparations

#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAXN = 12;

template <class T> string toStr(const T &x)
{stringstream s; s << x; return s.str();}

template <class T> int toInt (const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


// I have to search help , this is not entirelyly thoug by me;

ii plane [MAXN+1];
int partner[MAXN+1], next_rigth[MAXN+1];
int N;

bool exist_cicle()
{
    for(int i = 1; i <= N; ++i)
    {
        int cur = i;
        for(int cont = 0; cont < N; ++cont)
        {
            cur = next_rigth[partner[cur]];
        }

        if(cur != 0)  return true;
    }

    return false;

    cout << endl;
}

int solve()
{
    int i , total = 0;;
    for(i = 1; i <= N; ++i)
        if(partner[i] == 0) break;

    if(i > N)
    {
        if(exist_cicle()) return 1;
        return 0;
    }

    int j;
    for(j = i+1; j <= N; ++j)
     if(partner[j] == 0)
     {
        partner[i] = j;
        partner[j] = i;
        total += solve();
        partner[j] = 0;
     }
     partner[i] = 0;

    return total;
}

int main()
{
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    cin >> N;
    for(int i = 1; i <= N; ++i)
    {
        int x,y;
        cin >> x >> y;
        plane[i] = (ii(x,y));
    }

    for(int i = 1; i <= N; ++i)
    {
        int xi = plane[i].first;
        int yi = plane[i].second;
        for(int j = 1; j <= N; ++j)
        {
            int xj = plane[j].first;
            int yj = plane[j].second;
            if(xj > xi && yj == yi)
                if(next_rigth[i] == 0 || xj - xi <  plane[next_rigth[i]].first - xi)
                    next_rigth[i] = j;
        }
    }

//    for(int i = 0; i <= N-2; i+=2)
//    {
//        cout << plane[i].first << plane[i].second <<  " -> " << plane[i+1].first << plane[i+1].second << endl;
//    }

    cout << solve() << endl;
    return 0;
}

