#include <iostream>
#include <map>
using namespace std;

map<char,char> m;
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string r = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

bool isPalindrome(string s){
  int n = s.size();
  for(int i = 0; i < ( n / 2) + 1; ++i){
    if(s[i] != s[n - i - 1])
      return false;
  }
  return true;
}

bool isMirrow(string s){
  for(int i = 0; i < s.size() / 2 + s.size() % 2; i++){
    if(s[s.size() - 1 - i] != m[s[i]])
      return false;
  }
  return true;
}

int main(){
  string in;
  for(int i = 0; i < s.size(); i++)
    m[s[i]] = r[i];
  while(cin >> in){
    bool palindrome = isPalindrome(in);
    bool mirrow = isMirrow(in);
    if( palindrome && !mirrow)
      cout << in << " -- "<< "is a regular palindrome." << endl << endl;
    else if(!palindrome && mirrow)
      cout << in << " -- " << "is a mirrored string." << endl << endl;
    else if(palindrome && mirrow)
      cout << in << " -- " << "is a mirrored palindrome." << endl << endl;
    else
      cout << in << " -- " << "is not a palindrome." << endl << endl;
  }
  return 0;
}
