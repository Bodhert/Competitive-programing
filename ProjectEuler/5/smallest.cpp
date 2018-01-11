#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main() {

    ll arr[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int sizeArr = 19;
    ll ans = arr[0];

    for(int i = 1; i < sizeArr; ++i )
        ans = abs(ans*arr[i])/(__gcd(ans,arr[i]));

    cout << ans << endl;

    return 0;
}

