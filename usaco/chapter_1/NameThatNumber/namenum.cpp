/*
ID: alejand24
TASK: namenum
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;
using namespace std;
set<string> names;
vector <string> tags[10];
vector <string> allNames;
string num;
template <class T> int toInt(const T &x)
{
    stringstream s; s << x; int r; s >> r; return r;
}

void readDic()
{
    ifstream dictxt("dict.txt");
    string name;
    cin.rdbuf(dictxt.rdbuf());
    while(cin >> name)
    {
        names.insert(name);
    }
    dictxt.close();
}

void assignSerial()
{
    tags[2].push_back("A");
    tags[2].push_back("B");
    tags[2].push_back("C");

    tags[3].push_back("D");
    tags[3].push_back("E");
    tags[3].push_back("F");

    tags[4].push_back("G");
    tags[4].push_back("H");
    tags[4].push_back("I");

    tags[5].push_back("J");
    tags[5].push_back("K");
    tags[5].push_back("L");

    tags[6].push_back("M");
    tags[6].push_back("N");
    tags[6].push_back("O");

    tags[7].push_back("P");
    tags[7].push_back("R");
    tags[7].push_back("S");

    tags[8].push_back("T");
    tags[8].push_back("U");
    tags[8].push_back("V");

    tags[9].push_back("W");
    tags[9].push_back("X");
    tags[9].push_back("Y");

}

void generateAllPosiblesNames(string currNum, string currWord) // lo esta haciendo bien pero se estan repitiendo muchos calculos
{
    if(num.size() == currWord.size())
    {
        if(names.count(currWord)) allNames.push_back(currWord);
        return;
    }

    int pos = toInt<char>(currNum[0]);
    for(int i = 0; i < 3; ++i)
    {
        string curr;
        curr = currWord + tags[pos][i];
        generateAllPosiblesNames(currNum.substr(1,currNum.size()-1),curr ); // se que el llamado va estar malo
    }
    return;
}

int main()
{
   readDic();
   assignSerial();
   ifstream in("namenum.in");
   cin.rdbuf(in.rdbuf());
   cin >> num;
   ofstream out("namenum.out");

   generateAllPosiblesNames(num,"");

   sort(allNames.begin(),allNames.begin() + allNames.size());

   if(allNames.size() == 0) out << "NONE" << endl;
   else
   {
     for(int i = 0; i < allNames.size(); ++i)
     {
       out << allNames[i] << endl;
     }
   }


   //out << num;
   in.close();
   out.close();

    return 0;
}

