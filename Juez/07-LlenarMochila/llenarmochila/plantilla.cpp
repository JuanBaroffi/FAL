#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habrá vectores de más de dos millones de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  P = { 0 < n <= tam(a)}
*/

int llena_mochila(const int a[], int n, int k); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
  Q = { sumatorio(a,i,j) = SUMA x : i < x <= j : a[x]  ^
  res = max i,j : 0 <= i <= j < n ^ (sumatorio(a,i,j) <= k): sumatorio(a,i,j)
  }

	 
 */
 

/*
DISEÑO DEL ALGORITMO:

Paso 1. Variables
i -> Inicio de ventana
j -> Fin de ventana
peso -> Peso de la mochila
res -> Número de productos máximos que entran en la mochila
cont -> Contador local para la sequencias de elementos

Paso 2. Invariante
  sumatorio(a,i,j) = SUMA x : i < x <= j : a[x]  ^
  res = max i,j : 0 <= i <= j <= n ^ (sumatorio(a,i,j) <= k): sumatorio(a,i,j) ^
  0 <= i <= n ^ 1 <= j <= n ^ 1 <= cont <= n ^
  peso = sumatorio(a,i,j-1)

Paso 3. Inicialización
int i = 0;
	int j = 1;
	int peso = a[0];
	int res = 1;
	int cont = 1;

Paso 4. Condición del bucle, y código tras el bucle.
while (j < n){...}
return res;
	
Paso 5. Cuerpo del bucle
if (a[j] + peso <= k)
{
	peso += a[j];
	cont++;
	if (cont > res)
	{
		res = cont;
	}
	j++;
}
else {
	peso -= a[i];
	cont--;
	i++;
}

Paso 6. Justificación de que el algoritmo siempre termina.
 Cota: 2n - (ini + fin)
 
Paso 7. Complejidad:
El algoritmo realiza n iteracciones
por lo tanto la complejidad es Theta(n)
 
*/

int llena_mochila(const int a[], int n, int k) {
	  // A IMPLEMENTAR
	int i = 0;
	int j = 1;
	int peso = a[0];
	int res = 1;
	int cont = 1;

	while (j < n)
	{
		if (a[j] + peso <= k)
		{
			peso += a[j];
			cont++;
			if (cont > res)
			{
				res = cont;
			}		
			j++;
		}
		else {
			peso -= a[i];
			cont--;
			i++;
		}
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
		   int k;
		   cin >> k;
		   cout << llena_mochila(a, n, k) << endl;
	   }
   }
   while (n != -1);
}