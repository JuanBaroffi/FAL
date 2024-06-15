#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  P = {0 <= n <= tam(a)}
*/

 
bool misterio(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
   int resul = 0;
   for (int i = 0; i < n && resul >= 0; i++)
   {
      resul += a[i];
   }
   
   return resul == 0;
} 

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso 
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema
   
   O(n): Se trata de una complejidad lineal en el peor caso y O(1) en el mejor
*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR */

void lee_vector(int a[], int & n) {
	cin >> n; 
   for (int i=0; i < n; i++) {
	   cin >> a[i]; 
   }   
}

int main() {
	static int a[TMAX];
	int n;
   do {
	   lee_vector(a,n); 
	   if (n>=0) {
         if (misterio(a,n))
         {
		   cout << "SI" << endl;
         }else{
         cout << "NO" << endl;
         }
         
	   }
   }
   while (n != -1);
}