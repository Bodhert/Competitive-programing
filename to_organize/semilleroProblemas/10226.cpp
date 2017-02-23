#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

 
map<string,double> trees;
vector<string> existencia;

int main(){
  int t;
  string tree;
  
  cin >> t;
  getline(cin,tree);
  getline(cin,tree);
  cout << setprecision(4) << fixed;
  for(int i = 0; i < t; i++){
    
    if(i > 0) cout << endl;
    
    trees.clear();
    
    int total = 0;
    
    
    while(getline(cin,tree) && tree != ""){
      //cout << tree << "sdfasd" << endl;
      
      if(trees.count(tree)){
	trees[tree] += 1;
    
      }else{
	trees[tree] = 1;
	
      }

      total++;
    }

   
    for(map<string,double>::iterator it = trees.begin(); it != trees.end(); ++it){
      double result = 0.0;
      result = (it -> second / total) * 100.0;
      //cout << result << endl;
      cout << it -> first << ' '  <<  result << endl;
      //cout << it -> first << ' ' <<  it -> second << endl;
    }

    
  }
  return 0;
  
}
