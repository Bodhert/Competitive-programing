#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;
int alphabet[MAXN];


void clean()
{
    for(int i = 0; i < MAXN; ++i) alphabet[i] = 0;
}

int main()
{
    string in;
    bool out = false;
    cin >> in;
    clean();
    for(int i = 0; i < in.size() && !out ; ++i)
    {
        int pos  = in[i] - 'a';
        alphabet[pos]++;
        if(alphabet[pos] > 1)
        {
            out = true;
            cout << "no" << endl;
        }
    }

    if(!out) cout << "yes" << endl;
    
    return 0;
}