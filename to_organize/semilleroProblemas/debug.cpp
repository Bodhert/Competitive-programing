#include <iostream>
using namespace std;

int main(){
  int linenumbers;
  string line;
  cin >> linenumbers;
  getline(cin,line);
   while(linenumbers--){
      getline(cin,line);
      cout << line << endl;
      // for(int j = 0; j < line.size(); j++){
	
      // 	for(int k = 0; k < find.size(); k++){
      // 	  if(line[j] == find[k]) result += line[j];
      // 	}
	
      // }
      
   }

  return 0; 
}
