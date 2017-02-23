#include <iostream>
#include <algorithm>
using namespace std;

string clean(string n){
  string result;
  for(int i  = 0; i < n.size(); i++){
    if(n[i] != ' ' && n[i] != '.' &&  n[i] != ',' && n[i] != '!' &&
       n[i] != '?')
      result += n[i];
  }
  //  cout << result << endl;
  return result;
}

bool isPalindrome(string n){
  for(int i = 0; i < n.size(); i++){
    if(n[n.size() - 1 - i] != n[i])
      return false;
  }
  return true;
}

string toLower(string n){
  for(int i = 0; i < n.size(); i++){
    n[i] = tolower(n[i]);
  }
  return n;
}

int main(){
  string in;
  while(getline(cin,in) && in != "DONE"){
    string toCheck = clean(in);
    toCheck = toLower(toCheck);
    //cout << in << endl;
    // cout << toCheck << endl ;
    bool palin = isPalindrome(toCheck);
    if(palin)
      cout << "You won't be eaten!" << endl;
    else
      cout << "Uh oh.." << endl;
  }
  return 0;
}
