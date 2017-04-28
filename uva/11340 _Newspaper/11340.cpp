#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;
map<char,int> m;
map<char,int> cont;
// sumo 00 // debug
int main(){
  int cases, paid, value, linenumbers;
  char letter;
  string line;
  
  cin >> cases;
  while(cases--){
    m.clear();
    
    cin >> paid;
    string find;
    
    while(paid--){
      cin >> letter >> value;
      //cout << letter << " " <<paid << endl;
      m[letter] = value;
      cont[letter] = 0;
      find += letter;
    }
    
    
    string result;
    cin >> linenumbers;
    getline(cin,line);
    
    
    
    
    while(linenumbers--){
      getline(cin,line);
      //cout << line << endl;
      for(int j = 0; j < line.size(); j++){
	
      	for(int k = 0; k < find.size(); k++){
      	  if(line[j] == find[k]) result += line[j];
      	}
	
      }
      
    }

    //cout << "string final " << result << endl;

    int acum = 0;
    for(int i = 0; i < result.size(); i++){
      acum += m[result[i]];
    }
    
    stringstream ss;
    ss << acum;
    string gg = ss.str();
    string output;
    if(gg.size() == 1){
      cout << "0.0" << gg << "$" << endl;
    }else if(gg.size() == 2){
      cout << "0." << gg << "$" << endl;
    }else{
      cout << gg.substr(0,gg.size()-2) << "." << gg.substr(gg.size() - 2,gg.size()) << "$" << endl;

	}
      
      // cout << gg << endl;
      //cout << acum << endl;
    
  }
  
  return 0;
}
