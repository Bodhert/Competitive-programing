#include <bits/stdc++.h>
using namespace std;


int main()
{
    bool caps = true;
    string ans;
    string in;
    int size;

    cin >> size;
    getline(cin,in);
    getline(cin,in);
    
    for(int i = 0; i < size; ++i)
    {
        if(isalpha(in[i]))
        {
            if(caps)
            {
                ans += toupper(in[i]);
                caps = false;
            } 
            else
            {
                ans += tolower(in[i]);
                caps = true;
            }
        }
        else
        {
            ans += in[i];
        }
    }

    cout << ans << endl;




    return 0;
}