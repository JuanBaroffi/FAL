#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  P = { 0 < n <= tam(a)}

*/
bool es_gaspariforme(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
  Q = { sumatorio(a,i,j) = SUMA x: i <= x <= j: a[x] ^
  resul = PARATODO i : 0 <= i < n - 1 : sumatorio(a,0,i) >= 0 ^ sumatorio(a,0,n-1) = 0 }
	 
 */
 

/*
DISE�O DEL ALGORITMO:
-- Especifica cada paso del dise�o en cada apartado indicado

Paso 1. Variables
sum -> Suma de los elementos actual
res -> Si es gaspariforme o no
i -> Iterador para recorrer los elementos

Paso 2. Invariante
sumatorio(a,i,j) = SUMA x: i <= x <= j: a[x] ^
resul = PARATODO i : 0 <= i <= n - 1 : sumatorio(a,0,i) >= 0 ^ sumatorio(a,0,n) = 0 ^
0 <= i <= n ^
sum = sumatorio(a,0,n) 

Paso 3. Inicializaci�n
int i = 0;
int sum = 0;
bool res = false;


Paso 4. Condici�n del bucle, y c�digo tras el bucle
 while (i < n){...}
 return res;


Paso 5. Cuerpo del bucle
 sum += a[i];
		 if (i != n - 1 && sum <= 0)
		 {
			 i = n - 1;
		 }
		 else if (i == n - 1 && sum == 0)
		 {
			 res = true;
		 }
		 i++;


Paso 6. Justificaci�n de que el algoritmo siempre termina
Cota = n - i, ya que i siempre aumenta hasta que la cota llega a un suelo.


Paso 7. Complejidad
El algoritmo realiza n iteracciones
por lo tanto la complejidad es Theta(n)

*/

 
  
 bool es_gaspariforme(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	
	 int i = 0;
	 int sum = 0;
	 bool res = false;

	 while (i < n)
	 {
		 sum += a[i];
		 if (i != n - 1 && sum <= 0)
		 {
			i = n - 1;
		 }
		 else if (i == n - 1 && sum == 0)
		 {
			res = true;
		 }
		 i++;
	 }
	
	 return res;
 } 


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

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
		 if (es_gaspariforme(a,n)) 
           cout << "SI" << endl;
         else  
           cout << "NO" << endl;			 
	   }
   }
   while (n >= 0);	
}