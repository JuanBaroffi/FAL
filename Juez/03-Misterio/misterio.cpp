#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  P = { 0 < n <= tam(a) ^ P.t i : 0 < i < tam(a) : a[i-1] <= a[i]}
*/

 
int misterio(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
   int result = a[0];
   int max_repetidos = 0;
   int repetidos = 0;

   for (int i = 1; i < n; i++)
   {
      if (a[i] == a[i-1])
      {
         repetidos++;
         if (repetidos > max_repetidos)
         {
            max_repetidos = repetidos;
            result = a[i];
         }
         
      }else{
         repetidos = 0;
      }
      
   }
   return result;
} 

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso 
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema
   O(n): Complejidad lineal en el caso peor
   
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
		   cout << misterio(a, n) << endl;
	   }
   }
   while (n != -1);
}