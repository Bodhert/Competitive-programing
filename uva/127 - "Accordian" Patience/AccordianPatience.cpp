using namespace std;
#include <bits/stdc++.h>
#define MAXN 52
vector< stack<string> > game;

int main()
{
  string card;

  while (cin >> card && card != "#")
  {
    game.assign(MAXN,stack<string>());
    game[0].push(card);
    for(int i = 1 ; i <= 51; ++i)
    {
      cin >> card;
      game[i].push(card);
    }

    char ran;
    char suit;
    string actC;
    int i = 0;
    while(i < game.size())
    {
      actC = " ";
      ran  = ' ';
      suit = ' ';
      bool firstMove = false;
      bool move = false;

      if(!game[i].empty())
      {
        actC = game[i].top();
        ran = actC[0];
        suit = actC[1];
      }

      if((i-3) >= 0)
      {

        if(!game[i-3].empty())
        {

          string temp = game[i-3].top();
          char tempRan = temp[0];
          char tempSui = temp[1];
          if(tempRan == ran || tempSui == suit)
          {
            firstMove = true;
            game[i-3].push(actC);
            game[i].pop();
            if(game[i].empty()) game.erase(game.begin()+i);
            i = 0;
            move = true;
          }
        }
      }
      if((i-1 >= 0) && (!firstMove))
      {
        if(!game[i-1].empty())
        {
          string temp = game[i-1].top();
          char tempRan = temp[0];
          char tempSui = temp[1];
          if(tempRan == ran || tempSui == suit)
          {
            game[i-1].push(actC);
            game[i].pop();
            if(game[i].empty()) game.erase(game.begin()+i);
            i = 0;
            move = true;
          }
        }
      }
      if(!move) i++;
    }

    cout << game.size() << " piles remaining: ";
    for(int j = 0; j < game.size();++j)
    {
      if(!game[j].empty() && j != game.size()-1)
      {
        cout << game[j].size() << " ";
      }else if (!game[j].empty() && j == game.size()-1)
      {
        cout << game[j].size();
      }
    }
    cout << endl;
  }
  return 0;
}
