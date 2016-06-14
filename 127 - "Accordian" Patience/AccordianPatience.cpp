using namespace std;
#include <bits/stdc++.h>
#define MAXN 56
vector< stack<string> > game;


int main()
{
  string card;

  while (cin >> card && card != "#")
  {
    game.assign(MAXN,stack<string>());

    // cout << card << " ";
    game[0].push(card);
    // cout << "en el stack esta: " << game[0].top() << " " << endl;
    for(int i = 1 ; i <= 51; ++i)
    {
      cin >> card;
      game[i].push(card);
      // cout << "en el stack esta: " << game[i].top() << " " << endl;
      // cout << card << " " << endl;
    }
    int act = 0;
    char ran;
    char suit;
    string actC;
    cout << game.size() << " maraja ";
    cout << "jijij" << endl;
    for(int i = a; i < game.size();++i) // problema en el ciclo
    {
      cout << "dentro del ciclo ";
      actC = " ";
      ran  = ' ';
      suit = ' ';
      if(!game[i].empty())
      {
        actC = game[i].top();
        ran = actC[0];
        suit = actC[1];
      }

      if(i + game.size()-1 <= game.size())
      {
        if(!game[i+3].empty())
        {
          string temp = game[i+3].top();
          char tempRan = temp[0];
          char tempSui = temp[1];
          if(tempRan == ran || tempSui == suit)
          {
            game[i+3].push(actC);
            game[i].pop();
            if(game[i].empty()) game.erase(game.begin()+i);
            act = 0;
            cout << "primer if ";
          }
        }
      }
      else if(i+1 < game.size())
      {
        string temp = game[i+1].top();
        char tempRan = temp[0];
        char tempSui = temp[1];
        if(tempRan == ran || tempSui == suit)
        {
          game[i+1].push(actC);
          game[i].pop();
          if(game[i].empty()) game.erase(game.begin()+i);
          act = 0;
          cout << " segundo if ";

        }
      }
    }

    cout << "jiojoj" << endl;

    int cont =0;
    for(int j = 0; j < game.size(); ++j)
    {
      if(!game[j].empty()) cont++;
    }

    cout << "contador: " << cont << endl;
    cout <<  "size de my vector" << game.size() << endl;

    // cout << endl;
  }
  return 0;
}
