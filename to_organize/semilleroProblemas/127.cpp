#include <stack>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
  string in, final;
  char value,suit;
  while(getline(cin,in) && in != "#"){
    getline(cin,final);
    cout << in << final << endl;
  }
   
  return 0;
}
