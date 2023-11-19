
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
 


int tramo_mas_corto(bool a[], int n, int k) {
   // A IMPLEMENTAR	   
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
	
	