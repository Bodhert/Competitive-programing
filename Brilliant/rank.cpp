#include <bits/stdc++.h>
using namespace std;

int main()
{
  string word = "RANK";
  sort(word.begin(),word.end());
  int i = 1;
  do
  {
    i++;
  }while(next_permutation(word.begin(), word.end()) && word != "RANK");
  cout << "Order: " << i++ << " " << word << '\n';
  return 0;
}


// if all words formed using only letters of the word "RANK" exactly once are
// arranged alphabetically. Find the position of the word RANK.
