/*
ID: alejand24
TASK: beads
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;


using namespace std;


 // inidice the last visited
int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int N;
    string necklace;

    cin >> N;
    cin >> necklace;
    int maxi = -1;
    char curr = 'w', last = 'w';
    // guardar un lastpos

    for(int i = 0; i < N; ++i)
    {
        vector<bool> visited;
        visited.assign(N,0);
        if(necklace[i] != 'w') curr =  necklace[i];
        int j = i , cont = 0, k , far = 0;
        for(int contj = 0; contj < N;++contj)
        {
            if(curr != necklace[j] && necklace[j] != 'w') break;
            cont++; far++;
            visited[j]=1;
            j++;
            j %= N;
        }

        k = ((i-1)+N)%N;
        int contK = 0;
        if(necklace[k] != 'w') last = necklace[k];
        for(int contK = 0; contK < N ; ++contK)
        {
            if(last != necklace[k] && necklace[k]!= 'w') break;
            if(visited[k] == 1) break;
            cont++;
            k = ((k-1)+N)%N;
        }


        maxi = max(maxi, cont);
    }

    cout << maxi << endl;


    return 0;
}

