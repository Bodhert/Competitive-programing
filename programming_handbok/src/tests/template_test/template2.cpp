#include <bits/stdc++.h> // en caso de que se genere compilation error por este include, hacer los includes necesarios para el ejercicio
#define D(x) cout << "DEBUG: " << #x "=" << x << endl; // imprime rapidamente el nombre de la variable y su valor 

using namespace std;

/*
la mayoria de los jueces, no requieren de estas lineas
debido a que leen de consola  probablemente untilizando	
redireccionamiento de archivos , NO OLIVDAR comentar 
estas lineas cuando se envie el ejercicio, debido a que
esta hecho con el propositio de ahorrarnos tiempo al ingresar
los datos de prueba.
*/

int main() // lee dos enteros de un archivo llamado in.in y los escribe un archivo
{    	   // llamado out.out
    ofstream fout ("out.out");  
    ifstream fin ("in.in"); 
    
    //freopen("in.in","r",stdin);  // me permiten hacer directamente cin y cout, 
    //freopen("out.out","w",stdout); // igual que con scanf, ademas es opcioal el
                                   // out si no deseo copiar en un archivo

	
    int a, b;
 
    fin >> a >> b;
    fout << a << " " << b << endl;
    // cin >> a >> b;
    //cout << a << " " << b << endl;	
  
    return 0;
}

/*
es imortante resaltar que los archivos "in.in" debe de estar en 
la misma carpeta del programa
  
 */

