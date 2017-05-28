#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;  // cambiar despues  al verdadero maxn
int memo[3] , mods[MAXN];

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
        int ans = 0;
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
                    // mods[i] = (in[i] - '0') % 3;
                    // memo[mod]++
                }
                else if(mods[i-1] != -1)
                {
                    int actual  = in[i] - '0';
                    int mod = (mods[i-1] + actual) % 3;
                    mods[i] = mod;
                    memo[mod]++;
                    ans += memo[mod];
                }
            } else clearMemo();
        }
        cout << ans << endl;
    }
    return 0;
}