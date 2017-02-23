#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
//Anagram
bool compare(char a, char b){
  char lower_a = tolower(a), lower_b = tolower(b);
  if(lower_a == lower_b)
    return a < b;
  else
    return lower_a < lower_b;
}// nececito que me expliquen bien esta funcion


int main(){
  int cases;
  string in;
  cin >> cases;
  while(cases--){
    cin >> in;
    sort(in.begin(),in.end(),compare);
    //cout << in << endl;
     do
       cout << in << endl;
     while(next_permutation(in.begin(), in.end(),compare));
    
  }
  return 0; 
}
