
#include <iostream>

using namespace std;


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  
*/

int tramo_mas_corto(bool a[], int n, int k); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
     

	 
 */
 

/*
DISEÑO DEL ALGORITMO:

Paso 1. Variables


Paso 2. Invariante
     

Paso 3. Inicialización

Paso 4. Condición del bucle, y código tras el bucle.

	
Paso 5. Cuerpo del bucle

Paso 6. Justificación de que el algoritmo siempre termina.
 
 
Paso 7. Complejidad:

 
*/
 

//O (n^2)
int tramo_mas_cortoCuadratico(bool a[], int n, int k) {
   // A IMPLEMENTAR
	int res = 0;
	int i = 0;
	int j = 0;
	int cont = 0;
	int minTramo = n + 1;


	while (i < n) {
		if (a[i])
		{
			cont++;
			j = i+1;
			while (j < n && cont != k)
			{
				if (a[j])
				{
					cont++;
				}
				j++;
			}
			if (cont == k)
			{
				res = j - i;
				if (res < minTramo)
				{
					minTramo = res;
				}
			}
				cont = 0;
		}
		i++;
	}

	return minTramo;
}	


int tramo_mas_corto(bool a[], int n, int k) {
	int minTramo = n + 1;
	int cont = 0;
	int left = 0;

	for (int right = 0; right < n; ++right) {
		if (a[right]) {
			++cont;
		}

		while (cont == k) {
			minTramo = std::min(minTramo, right - left + 1);
			if (a[left]) {
				--cont;
			}
			++left;
		}
	}

	return minTramo;
}


/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA: 
   NO MODIFICAR */

   
void lee_caso(int& n, bool a[], int& k) {
	cin >> n;
	if (n != -1) {
		for (int i = 0; i < n; i++) {
			int elem;
			cin >> elem;
			a[i] = bool(elem);
		}
		cin >> k;
	}
}

const int MAX_TAM = 100;
int main() {
	int n;
	bool a[MAX_TAM];
	int k;
	do {
		lee_caso(n, a, k);
		if (n != -1) {
			cout << tramo_mas_corto(a, n, k) << endl;
		}
	} while (n != -1);
}
	
	