#include <iostream>
#include <string>
using namespace std;

int main(){
  string in,clean;
  while(cin >> in){
    string begin,end,fbegin,fend, copy;
    copy = in;
    
    for(int i = 0; i < in.size(); i++){
      if(copy[i] == '3'){
	copy[i] = 'E';
      }else if(copy[i] == '2'){
	copy[i] = 'S';
      }else if (copy[i] == '5'){
	copy[i] = 'Z';
      }
    }

    //     cout << copy << endl;
     if(copy.size() % 2 != 0){
       for(int i = 0; i <= copy.size()/2; i++){
	 begin += copy[i];
	 fbegin += in[i];
       }
     }else{
       for(int i = 0; i < copy.size()/2; i++){
	 begin += copy[i];
	 fbegin += in[i];
       }
     }
     
    if(in.size() > 1){
      for(int i = copy.size()-1; i >= copy.size()/2; i--){
	end += copy[i];
	fend += in[i];
      }
    }else{
      end += copy[0];
      fend += in[0];
    }

    //        cout << begin << " " << end << endl;

    int cont = 0;
    bool mirrow = false;
    for(int i = 0; i < fbegin.size() && i < fend.size();i++){
      if(fbegin[i] == 'A' && fend[i] == 'A')
	cont++;
      else if(fbegin[i] == 'H' && fend[i] == 'H')
	cont++;
      else if(fbegin[i] == 'M' && fend[i] == 'M')
	cont++;
      else if(fbegin[i] == 'O' && fend[i] == 'O')
	cont++;
      else if(fbegin[i] == 'T' && fend[i] == 'T')
	cont++;
      else if(fbegin[i] == 'V' && fend[i] == 'V')
	cont++;
      else if(fbegin[i] == 'W' && fend[i] == 'W')
	cont++;
      else if(fbegin[i] == 'X' && fend[i] == 'X')
	cont++;
      else if(fbegin[i] == 'Y' && fend[i] == 'Y')
	cont++;
      else if(fbegin[i] == '1' && fend[i] == '1')
	cont++;
      else if(fbegin[i] == '8' && fend[i] == '8')
	cont++;      
    }

    if(cont == fbegin.size() || cont == fend.size())
      mirrow = true;
    
    if(fbegin == fend && !mirrow){
      cout << in << " -- "<< "is a regular palindrome." << endl;
    }else if (begin == end && !mirrow){
      cout << in << " -- " << "is a mirrored string." << endl;
    }else if(fbegin == fend && mirrow){
      cout << in << " -- " << "is a mirrored palindrome." << endl;
    }else{
      cout << in << " -- " << "is not a palindrome." << endl;
    }
    cout << endl;
  }
    
  return 0;
}
