#include <bits/stdc++.h>
using namespace std;

int arr[3];

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    arr[0] = a, arr[1] = b, arr[2] = c;
    sort(arr, arr + 3);
    cout << arr[0] + arr[1] << endl;
    return 0;
}