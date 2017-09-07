#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    string in;
    cin >> n;
    getline(cin,in);
    while(n--)
    {
        string out = "";
        getline(cin,in);
        for(int i = 0; i < in.size(); ++i)
        {
                out += in[i];
                if(in[i] == 'a') out += "pa";
                else if(in[i] == 'e') out += "pe";
                else if(in[i] == 'i') out += "pi";
                else if(in[i] == 'o') out += "po";
                else if(in[i] == 'u') out += "pu";
        }

        cout << out << endl;

    }

    return 0;
}
