/*
  How many positive divisors does the following number have:
  7^10+7^11+7^12+7^13
*/

#include<iostream>
#include <math.h> 

using namespace std;

int main(){
  unsigned long long int num = 112990099600; // = 7^10+7^11+7^12+7^13
  int root = sqrt(num);
  cout << root << endl;
  int cont = 0;
  for( unsigned long long int i = 1; i <= num; ++i){
    if(num % i == 0) cont++;
  }
  cout << cont << endl;
}
