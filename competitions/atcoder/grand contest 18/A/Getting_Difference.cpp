#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
    freopen("in","r",stdin); 
    int arr[MAXN];
    int n,k,a1;
    int M = -1, gdc1 = 0;
    cin >> n >> k;

    for(int i = 0; i < n; ++i )
    {
        cin >> a1;
        arr[i] = a1;
        if(a1 > M) M = a1;
    }

    for(int i = 0; i < n - 1; ++i)
    {
        gdc1 = gcd(arr[i],arr[i+1]);
    }

    if(k%gdc1 == 0 && k < M) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

   
    
    
    return 0;
}