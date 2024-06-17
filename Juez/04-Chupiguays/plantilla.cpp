#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  P = { 0 <= n <= tam(a) }

*/
int num_chupiguays(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
  Q = { result = #i : 0 <= i < n : a[i] % (SUMA j : 0 <= j < i : a[j]) = 0 } 
 */
 

/*
DISE�O DEL ALGORITMO:
-- Especifica cada paso del dise�o en cada apartado indicado

Paso 1. Variables
sum -> Suma de los elementos actual
res -> N�mero de n�meros chupoguays
i -> Iterador para recorrer los elementos

Paso 2. Invariante
result = #i : 0 <= i <= n : a[i] % (SUMA j : 0 <= j < i : a[j]) = 0 ^
sum = (SUMA j : 0 <= j <= i : a[j]) ^
0 <= i <= n

Paso 3. Inicializaci�n
sum = 0
res = 0
i = 0

Paso 4. Condici�n del bucle, y c�digo tras el bucle
while (i < n) {...}
return res;


Paso 5. Cuerpo del bucle
if (sum == 0)
{
	if (a[i] == 0)
	{
		res++;
	}
}
else if (a[i] % sum == 0)
{
	res++;
}
sum += a[i];
i++;

Paso 6. Justificaci�n de que el algoritmo siempre termina
Cota = n - i, ya que i siempre aumenta hasta que la cota llega a un suelo.


Paso 7. Complejidad
El algoritmo realiza n iteracciones
por lo tanto la complejidad es Theta(n)

*/


int num_chupiguays(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int sum = 0;
	int res = 0;
	int i = 0;

	while (i < n)
	{
		if (sum == 0)
		{
			if (a[i] == 0)
			{
				res++;
			}
		}
		else if (a[i] % sum == 0)
		{
			res++;
		}
		sum += a[i];
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
		   cout << num_chupiguays(a, n) << endl;
	   }
   }
   while (n != -1);
}