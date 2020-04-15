#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << "Debug " << #x " = " << x << endl

int queries;

int query(int i)
{
    queries++;
    cout << i << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main()
{
    int tc, b;
    char judgeans = 'Y';
    cin >> tc >> b;

    while (tc-- && judgeans == 'Y')
    {
        queries = 0;
        int l = 0, r = b+1;
        vector<int> bits(b + 1);
        while(queries < 10){
            l++; r--;
            bits[l] = query(l);
            bits[r] = query(r);
        }
        // D(l); D(r);
        while (queries < 150 && l+1 < r)
        {
            // D(l); D(r);
            if ((queries + 1) % 10 == 1 && l+1 < r)
            {
                int same = -1, dif = -1;
                for (int i = 1; i <= l; ++i)
                {
                    if (bits[i] == bits[b + 1 - i])
                    {
                        same = i;
                    }
                    else
                    {
                        dif = i;
                    }
                }
                if (same == -1)
                {
                    query(1);
                    if (bits[1] != query(1))
                    {
                        for (int i = 1; i <= l; ++i)
                        {
                            bits[i] = !bits[i];
                        }
                        for (int i = r; i <= b; ++i)
                        {
                            bits[i] = !bits[i];
                        }
                    }
                }
                else
                {
                    int newsame = query(same);
                    int newdif = -1;
                    if(dif == -1)
                        query(1);
                    else
                        newdif = query(dif);
                    
                    if (bits[same] != newsame)
                    {
                        for (int i = 1; i <= l; ++i)
                        {
                            bits[i] = !bits[i];
                        }
                        for (int i = r; i <= b; ++i)
                        {
                            bits[i] = !bits[i];
                        }
                    }
                    if (dif != -1 && (newdif != bits[dif]))
                    {
                        reverse(bits.begin() + 1, bits.end());
                    } 
                    
                }
            }
            for(int i = 0; i < 4 ; ++i){
                l++; r--;
                bits[l] = query(l);
                bits[r] = query(r);
            }
        }

        for (int i = 1; i <= b; ++i)
        {
            cout << bits[i];
        }
        cout << endl;
        cin >> judgeans;
    }
    return 0;
}
