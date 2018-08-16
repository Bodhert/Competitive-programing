#include <bits/stdc++.h>
using namespace std;

#define D(x) cout << "DEBUG: " << #x " = " << x << endl

const int MAXN = 50; // max level of anidation
int currIndex = 0;
int id = 1;

struct Tag
{
    string name = "";
    Tag *parent;
    unordered_map<string, string> atributes;
    unordered_map<string, Tag *> children;
    Tag(string _name, Tag *parent, vector<string> &tokens) : name(_name), parent(parent)
    {
        // D(name);
        for (int i = 1; i <= tokens.size()-3 && tokens.size() >= 3; i += 3)
        {
            string atribute = tokens[i];
            string value = tokens[i + 2].substr(1, tokens[i + 2].size() - 2);
            // D(atribute); D(value); 
            atributes[atribute] = value;
        }
    }
};

string search(Tag *curr, string line)
{
    string tag = "", atribute = "", reaminingLine = "";
    size_t foundDot = line.find_first_of('.');
    size_t foundNeg = line.find_first_of('~');

    if (foundDot != string::npos)
    {
        reaminingLine = line.substr(foundDot + 1, line.size() - 1);
        tag = line.substr(0, foundDot);
        if(curr->children.count(tag))
            return search(curr->children[tag], reaminingLine);
        return "Not Found!";
    }
    else if (foundNeg != string::npos)
    {
        tag = line.substr(0, foundNeg);
        reaminingLine = line.substr(foundNeg+1, line.size() - 1);
        if(curr->children.count(tag))
            return search(curr->children[tag], reaminingLine);
        return "Not Found!";
    }
    else
    {
        if (curr->atributes.count(line))
            return curr->atributes[line];
        return "Not Found!";
    }
    return "Not Found!";
}

int main()
{
    // freopen("in3", "r", stdin); // for debug purposes

    int lines, queries;
    string in;
    cin >> lines >> queries;
    cin.ignore(INT_MAX, '\n');
    vector<string> empty;
    Tag root("root", NULL, empty);
    Tag *current = &root;

    while (lines--)
    {
        string instruction, currTag, toParse;
        getline(cin, toParse);

        toParse = toParse.substr(1, toParse.size() - 2);
        // D(toParse);
        istringstream iss(toParse);
        vector<string> tokens((istream_iterator<string>(iss)),
                              istream_iterator<string>());
        instruction = tokens[0];

        if (instruction[0] != '/')
        {
            currTag = instruction;
            current->children[currTag] = new Tag(currTag, current, tokens);
            current = current->children[currTag];
        }
        else
        {
            current = current->parent;
        }
    }

    while (queries--)
    {
        getline(cin, in);
        size_t foundNeg = in.find_last_of('~');
        if (foundNeg != string::npos)
            cout << search(&root, in) << endl;
        else
            cout << "Not Found!" << endl;
        // D(in);
    }
    return 0;
}
