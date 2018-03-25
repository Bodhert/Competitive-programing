#include <bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("in","r",stdin);

    int Nparticipants,Days,Xleft_chocolate,Ai , ans = 0;

    cin >> Nparticipants >> Days >> Xleft_chocolate;

    ans += Xleft_chocolate;

    for(int i = 0; i < Nparticipants; ++i)
    {
        cin >> Ai;
        for(int j = 0; j <= Days; ++j)
        {
            int day = (j*Ai + 1);
            if(day <= Days) ans++;
            else break;
        }
    }

    cout << ans << endl;


}

