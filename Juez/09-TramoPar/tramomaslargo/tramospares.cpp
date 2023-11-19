/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA: Juan Israel Baroffi Gonz�lez


Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo: 


*/


#include <iostream>
using namespace std;


/*

PRECONDICION DE LA FUNCION:
---Escribe aqu� la precondici�n de la funci�n.
P = { 0 < n <= tam(v)}

*/


int /* resul */ long_tramo_par_mas_largo(int v[], unsigned int n);

	/*
	   POSTCONDICION DE LA FUNCION:
	   ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
	   ---al valor devuelto por la funci�n, utiliza la pseudo-variable
	   ---'resul'
	(1) Definiciones auxiliares (si procede):
	pares(v,i,j) = PARATODO x : i < x <= j : a[x] % 2 = 0

	(2) Postcondici�n
	Q = { result = max i,j : 0 <= i <= j < n  ^ pares(v,i,j): j-i+1}


    */



	/* DISE�O DEL ALGORITMO:
	--- Detalla aqu� el proceso seguido para dise�ar el
	--- algoritmo

	PASO 1. Variables adicionales (aparte de los par�metros y el resultado)
	i -> Iterador para recorrer los elementos
	res -> Sequencia m�s larga de pares
	cont -> Contador local para las sequencias

	PASO 2. Invariante
	   (2.1) Definiciones auxiliares (si procede)
	   pares(v,i,j) = PARATODO x : i < x <= j : a[x] % 2 = 0
	   
	   
	   (2.2) Invariante
	 result = max i,j : 0 <= i <= j <= n  ^ pares(v,i,j): j-i+1 ^
	 0 <= i <= n ^ 0 <= cont <= n

	PASO 3. C�digo de inicializaci�n, justificando que, tras
	        dicho c�digo, se cumple el invariante
	int i = 0;
	int res = 0;
	int cont = 0;

	
	PASO 4. Condici�n del bucle, c�digo tras el bucle (si procede),
	        y justificaci�n de que, una vez finalizado el algoritmo,
			se cumple la postcondici�n
	while (i < n)
	{...}
	return res;

    PASO 5. Dise�o del cuerpo del bucle, justificando que dicho c�digo
	        preserva el invariante
	if (v[i] % 2 == 0)
	{
		cont++;
		if (cont > res)
		{
			res = cont;
		}
	}
	else {
		cont = 0;
	}
	i++;

	PASO 6: Expresi�n de cota y justificaci�n de que el algoritmo siempre 
	        termina
	Cota = n - i, ya que i siempre aumenta hasta que la cota llega a un suelo.


	PASO 7: Determinaci�n justificada de la complejidad del algoritmo
	El algoritmo realiza n iteracciones
	por lo tanto la complejidad es Theta(n)

	*/


int /* resul */ long_tramo_par_mas_largo(int v[], int n) {
	/* IMPLEMENTACION */

	int i = 0;
	int res = 0;
	int cont = 0;


	while (i < n)
	{
		if (v[i] % 2 == 0)
		{
			cont++;
			if (cont > res)
			{
				res = cont;
			}
		}
		else {
			cont = 0;
		}
		i++;
	}
	return res;
}	



/* PROGRAMA DE PRUEBA: No modificar */

const int MAX_ELEMS = 1000000;
 
bool ejecuta_caso() {
	int n;
	cin >> n;
	static int v[MAX_ELEMS];
	if (n == -1) return false;
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << long_tramo_par_mas_largo(v, n) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}