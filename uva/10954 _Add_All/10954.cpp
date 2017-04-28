#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> myset;
vector<int> myvect;

int main(){
  int size,num,cost,sum,finalcost;
  
  while(cin >> size && size){
    myset.clear();
    myvect.clear();
    
    for(int i = 0; i < size; i++){
      cin >> num;
      myset.insert(num);
    }

    
    for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it){
       myvect.push_back(*it) ;
    }

    //cost = 0; sum = 0;
    cost = myvect.at(0) + myvect.at(1);;
    cout << "costo actual:  " << cost << endl;
    finalcost = cost;
    int aux = cost;
    for(int i = 2 ;i < myvect.size(); i++){
      cost = myvect.at(i) + aux ;
      cout << "ciclo costo actual: " <<cost << endl;
      finalcost += cost;
      aux = cost;
    }

    cout << finalcost << endl;
    
     
    
  }
  
  
  return 0; 
}
