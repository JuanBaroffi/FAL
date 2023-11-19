#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habrá vectores de más de un millón de elementos



/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  P = { 0 < n <= tam(a)}
    

*/
int menor_moda(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
  Q = { cte(a,i,j) = PARATODO x : i < x <= j : a[i] = a[x]  ^
  maxCte(a,i,j) = max i,j : 0 <= i <= j < n ^ cte(a,i,j): a[i] ^
  res = min i : 0 <= i < n : maxCte(a,0,i)  }
*/


/*
DISEÑO DEL ALGORITMO:
-- Especifica cada paso del diseño en cada apartado indicado

Paso 1. Variables
i -> Iterador para recorrer los elementos
maxCons -> Sequencia más larga
res -> Elemento de la sequencia más larga
cont -> Contador local para las sequencias

Paso 2. Invariante
cte(a,i,j) = PARATODO x : i < x <= j : a[i] = a[x]  ^
maxCte(a,i,j) = max i,j : 0 <= i <= j <= n ^ cte(a,i,j): a[i] ^
res = min i : 0 <= i < n : maxCte(a,0,i) ^
1 <= i <= n ^ 1 <= cont <= n ^1 <= maxCons <= n

Paso 3. Inicialización
int i = 1;
int maxCons = 0;
int res = a[0];
int cont = 1;

Paso 4. Condición del bucle, y código tras el bucle
while (i < n){...}
return res;


Paso 5. Cuerpo del bucle
if (a[i] == a[i - 1])
{
	cont++;
	if (cont == maxCons)
	{
		if (a[i] < res)
		{
			res = a[i];
		}
	}
	if (cont > maxCons)
	{
		res = a[i];
		maxCons = cont;
	}
}
else {
	cont = 1;
}
i++;


Paso 6. Justificación de que el algoritmo siempre termina
Cota = n - i, ya que i siempre aumenta hasta que la cota llega a un suelo.


Paso 7. Complejidad
El algoritmo realiza n iteracciones
por lo tanto la complejidad es Theta(n)

*/

 
 
int menor_moda(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int i = 1;
	int maxCons = 0;
	int res = a[0];
	int cont = 1;
	while (i < n)
	{
		if (a[i] == a[i - 1])
		{
			cont++;
			if (cont == maxCons)
			{
				if (a[i] < res)
				{
					res = a[i];
				}
			}
			if (cont > maxCons)
			{
				res = a[i];
				maxCons = cont;
			}
		}
		else {
			cont = 1;
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
		   cout << menor_moda(a, n) << endl;
	   }
   }
   while (n != -1);
}