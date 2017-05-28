#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;  
int memo[3] , mods[MAXN];
typedef unsigned long long ll;

void clearMemo()
{
    memo[0] = 0;
    memo[1] = -1;
    memo[2] = -1;
}

void clearMods()
{
    for(int i = 0 ; i < MAXN; ++i) mods[i] = -1;
}

int main()
{
    string in;
    while(cin >> in)
    {
        clearMemo();
        clearMods();
        ll ans = 0;
        for(int i = 0; i < in.size(); ++i)
        {
            if(isdigit(in[i]))
            {
                if(i == 0) 
                {
                    int actual = in[i] - '0';
                    int mod =  actual % 3;
                    mods[i] = mod; 
                    memo[mod]++;
                    ans += memo[mod];
                }
                else if(isdigit(in[i-1]))
                {
                    int actual  = in[i] - '0';
                    int mod = (mods[i-1] + actual) % 3;
                    mods[i] = mod;
                    memo[mod]++;
                    ans += memo[mod];
                }
                else
                {
                    clearMemo();
                    int actual = in[i] - '0';
                    int mod = actual % 3;
                    mods[i] = mod;
                    memo[mod]++;
                    ans += memo[mod];
                } 
            } 
        }
        cout << ans << endl;
    }
    return 0;
}