/*
ID: alejand24
TASK: combo
LANG: C++11
*/

// this is not all came to me , i was doing somethin wrong with the comparations credits to the video

#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;

template <class T> string toStr(const T &x)
{stringstream s; s << x; return s.str();}

template <class T> int toInt (const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int N;

bool close(int a, int b)
{
    if(abs(a-b) <= 2 ) return true;
    if(abs(a-b) >= N-2 ) return true;
    return false;
}

bool close_enough(int a,int b, int c, int a1, int b1, int c1)
{
    return close(a,a1) && close(b,b1) && close(c,c1);
}

int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);

    int  f1, f2, f3, m1, m2, m3, ans = 0;

    cin >> N;
    cin >> f1 >> f2 >> f3;
    cin >> m1 >> m2 >> m3;

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            for(int k = 1; k <= N; ++k)
            {
                if(close_enough(i,j,k,f1,f2,f3) || close_enough(i,j,k,m1,m2,m3))
                {
                    //cout << i << " " << j << " " << k << endl;
                    ans++;
                }

            }
        }
    }

    cout << ans << endl;

    return 0;
}

