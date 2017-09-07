#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ni;
    vector<int> sim;
    vector<int> sequence;
    cin >> n;
    for(int i  = 0; i < n; ++i)
    {
        cin >> ni;
        sim.push_back(ni);
    }
    
    if(n%2 == 0)
    {
        for(int i = n; i > 0; i -= 2) sequence.push_back(i-1);
        for(int i = 1; i < n; i += 2) sequence.push_back(i-1);
    }
    else
    {
        for(int i = n; i > 0; i -= 2) sequence.push_back(i-1);
        for(int i = 2; i < n; i += 2) sequence.push_back(i-1);         
    }

    for(int i  = 0; i < n-1; ++i)
    {
       cout << sim[sequence[i]] << " ";
    }
       cout << sim [sequence[n-1]] << endl;

    return 0;
}