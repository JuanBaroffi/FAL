
#include <iostream>

using namespace std;


/*
DISEÑO DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de diseño realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- parámetro (en caso de que utilices una generalización), los casos base, y los 
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo diseñado.
-- Escribe y resuelve las ecuaciones de recurrencia.

*/

bool sumdivisibleAux(int n, int & dig, int & sum) {

	if (n / 10 == 0)
	{
		dig++;
		sum = n;
		return (n % dig == 0);
	}
	else {
		if (sumdivisibleAux(n / 10, dig, sum))
		{
			dig++;
			int c = sum + (n % 10);
			sum += n % 10;
			if (c % dig == 0)
			{
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		
	}

}

bool sumdivisible(int n) {
	/* IMPLEMENTACION:
	   Esta función será el punto de entrada a tu algoritmo.
	   Puedes implementar, además, las funciones auxiliares
	   que consideres oportuno.
	   -- n: El número cuya sumdivisibilidad debes determinar.
	   -- La función deberá devolver 'true' si n es sumdivisible,
	   -- y 'false' en otro caso
	*/
	int dig = 0;
	int sum = 0;
	return sumdivisibleAux(n, dig,sum);
}   


/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA: 
   NO MODIFICAR */

int main() {
	int n;
	do {
		cin >> n;
		if (n > 0) {
			if (sumdivisible(n)) 
				 cout << "SI" << endl;
			else 
                 cout << "NO" << endl;				
		}
	} while (n > 0);
}
	
	