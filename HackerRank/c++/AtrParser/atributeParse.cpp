#include <bits/stdc++.h> 
using namespace std;

#define D(x) cout << "DEBUG: " << #x " = " << x << endl

const int MAXN = 50; // max level of anidation
int currIndex = 0;
int nextIndex = 1;

struct Tag
{
    string name = "";
    map<string,string> atributes;
    Tag(string _name) : name(_name){}
};


vector<Tag> Tree[MAXN];
string currTag = "";

void parseAndStore(string toParse)
{
    string instruction;
    struct Tag* current = (struct Tag*)malloc(sizeof(struct Tag));
    toParse = toParse.substr(1, toParse.size() - 2);
    D(toParse);
    istringstream iss(toParse);
    vector<string> tokens((istream_iterator<string>(iss)),
                        istream_iterator<string>());
    instruction = tokens[0];

    if(instruction[0] != '/')
    {
        currTag = instruction;
    }
    else
        currTag = instruction.substr(1,instruction.size()-1);


    if(instruction[0] != '/')
    {
        Tree[currIndex].push_back(Tag(currTag));
        currIndex = nextIndex;
        nextIndex++;
    }
    else
    {
        currIndex--;
    }
}

int main()
{
    freopen("in", "r", stdin); // for debug purposes

    int lines, queries;
    string in;
    cin >> lines >> queries;
    cin.ignore(INT_MAX, '\n');
    while (lines--)
    {
        // cleaning the buffer special character that
        // stays there
        getline(cin, in);
        // D(in);
        parseAndStore(in);
    }

    while(queries--)
    {
        getline(cin,in);
        // D(in);
    }
    return 0;
}
