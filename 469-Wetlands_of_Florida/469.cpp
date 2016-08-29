#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
char M[105][105] ;
char cpy[105][105];

int floodfill1(int r, int c,int filas,int columnas){
  //cout << M[r][c];
  if(r < 0 || r >= filas || c < 0 || c >= columnas) return 0;
  if(cpy[r][c] != 'W') return 0;
  int ans = 1;
   cpy[r][c] = '.';
  for(int d = 0; d < 8; d++)
    ans += floodfill1(r + dr[d], c + dc[d],filas,columnas);
  return ans;
}

int main(){
  int casos,parejas;
  string in,aux;
  cin >> casos;
  
  while(casos--){
    cin >> in;
    
    for(int i = 0; i < 105; i++)
      for(int j = 0; j < 105; j++)
	M[i][j] = cpy[i][j] = 0;
    
    getline(cin,aux);
    in += aux;
    
    int filas = 0,columnas = 0;
    //cout << in.size() << endl;
    for(int i = 0; i < in.size(); i++)
      M[0][i] = in[i];
    
    filas++;
    columnas = in.size();
    
    int cont = 1;
    while(getline(cin,in)){
      if(in.size() == 0){
	cout << endl;
	break;
      }
      
      if(string::npos == in.find_first_of("0123456789")){
	filas++;
	for(int i = 0; i < in.size();i++)
	  M[cont][i] = in[i];
	
	cont++;
	//cout << in.size() << endl;
      }else{
	
	for(int i = 0; i < filas;i++){
	   for(int j = 0; j < columnas ;j++){
	      cpy[i][j] = M[i][j]; 
	   }
	 }
	
	int  num = in.find(" ",0);
        
	string numm1 = in.substr(0,num);
	string numm2 = in.substr(num,in.size()-1);
	
	stringstream ss(numm1);
	stringstream sss(numm2);
	
	int num1,num2;
	ss >> num1;
	sss >> num2;
	int respuesta =  floodfill1(num1 - 1,num2 - 1,filas,columnas);
	cout << respuesta << endl;

	
	 
      }
      
    }
    
  }
  return 0;
}

   			       
    

    
      
      
   
