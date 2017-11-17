/*
la mayoria de los jueces, no requieren de estas lineas
debido a que leen de consola, NO OLVIDAR comentar 
las lineas para abrir y escribir en archivos, 
y evitar WA  cuando se envie el ejercicio, debido a que
esta hecho con el propositio de ahorrarnos tiempo al ingresar
los datos de prueba.

PROG: el programa lee dos enteros de un archivo llamado in.in y 
los escribe en un archivo  out.out
*/

#include <bits/stdc++.h> // si no compila,hacer
                         //includes necesarios
#define D(x) cout << "DEBUG: " << #x "=" << x << endl; 
using namespace std;

int main()
{    	   
  //ofstream fout ("out.out");  
  //ifstream fin ("in.in"); 
  freopen("in.in","r",stdin);  //  directamente cin y cout, 
  freopen("out.out","w",stdout); // y  scanf.
  
  int a, b;
  //fin >> a >> b;
  //fout << a << " " << b << endl;
  cin >> a >> b;
  cout << a << " " << b << endl;
  
  return 0;
}
/*
es importante resaltar que el archivo "in.in" debe de estar en 
la misma carpeta del programa 
 */
