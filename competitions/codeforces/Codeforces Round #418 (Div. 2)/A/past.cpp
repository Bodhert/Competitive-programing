#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int MAXN = 105;




int main()
{
   // freopen("in1", "r", stdin); // debug purposes
    int n,k, An ,Bn;
    cin >> n >> k;
    int a[n], b[k];
    vi zeroes;

    for(int i = 0; i < n; ++i)
    {
        cin >> An ;
        a[i] = An ;
        if(An == 0) zeroes.push_back(i); 
    }

     for(int i = 0; i < k; ++i)
    {
        cin >> Bn ;
        b[i] = Bn ;
    }

    sort(b,b + k, greater<int>());

   

    for(int i = 0; i < k; ++i) a[zeroes[i]] = b[i];


    bool is_not_increasing = false;
    for(int i = 0; i < n && !is_not_increasing; ++i)
    {
        if(i!= 0 && i != n-1)
        {
            if(a[i] > a[i+1] || a[i] < a[i-1]) is_not_increasing = true;
        }

        if(i == 0  && a[i] > a[i+1])  is_not_increasing = true;
        if(i == n-1 && a[i] < a[i-1]) is_not_increasing = true;
    }
    
    if(is_not_increasing) cout << "yes";
    else cout << "no";


    
    return 0;
}
