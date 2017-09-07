#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100002;

int main()
{
    int memo[MAXN];
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for(int i = 4 ; i < MAXN; ++i)
    {
        memo[i] = memo[i-1] + 3;
    }

    int t,h;
    cin >> t;
    while(t--)
    {
        cin >> h;
        cout << memo[h] << endl;
    }

    return 0;
}
