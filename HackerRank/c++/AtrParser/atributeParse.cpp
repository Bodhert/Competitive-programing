#include <bits/stdc++.h> 
using namespace std;

#define D(x) cout << "DEBUG: " << #x " = " << x << endl

struct Tag
{
    string name = "";
    struct Tag* previous = NULL;
    map<string,string> atributes;
    map<string,Tag> branches;
    Tag(string _name,struct Tag* _previous) : name(_name), previous(_previous) {}
};

map<string,Tag*> trees;
string currTag = "";
struct Tag* current = NULL;

void parseAndStore(string toParse)
{
    string instruction;
    toParse = toParse.substr(1, toParse.size() - 2);
    D(toParse);
    istringstream iss(toParse);
    vector<string> tokens((istream_iterator<string>(iss)),
                        istream_iterator<string>());
    instruction = tokens[0];

    if(instruction[0] != '/')
    {
        if(currTag == "")
        {
            currTag = instruction;
            current = (struct Tag*)malloc(sizeof(struct Tag));
            current->name =  instruction;
            //asignar los atributos
        }
        else
        {
            currTag = instruction;
            struct Tag* branch = (struct Tag*)malloc(sizeof(struct Tag));
            branch->name = currTag;
            branch->previous = current;
            current->branches[currTag] = branch; // bug here in the insertion
            current = branch;
        }
    }
    else
    {
        string closingTag = instruction.substr(1,instruction.size()-1);

        if(currTag == closingTag && current->previous != NULL)
        {
            current = current->previous;
            currTag = current->name;
        }
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
