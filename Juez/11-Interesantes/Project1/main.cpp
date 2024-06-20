
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
//
//bool es_interesante_aux(int n, int& dr, int& iz) {
//	int ev = (n / 10);
//
//	if (ev == 0)
//	{
//		iz = n;
//		return true;
//	}
//	else {
//		int element = n % 10;
//		dr += element;
//		if (es_interesante_aux(n / 10, dr, iz) && element != 0)
//		{
//			if ((dr % element == 0) && (iz % element == 0))
//			{
//				iz += element;
//				dr -= element;
//				return true;
//			}
//			else {
//				return false;
//			}
//		}
//		else {
//			return false;
//		}
//	}
//}
bool es_interesante_aux(unsigned int n, int& sumaDerecha, int& sumaIzquierda) {
	int numero = n % 10;
	if (numero == 0)
	{
		return false;
	}
	else if ((n / 10) == 0)
	{
		sumaIzquierda += numero;
		return (numero != 0) && (sumaDerecha % numero == 0);
	}
	else {
		sumaDerecha += numero;
		bool aux = (es_interesante_aux((n / 10), sumaDerecha, sumaIzquierda));
		sumaDerecha -= numero;
		bool condSumaIzq = (sumaIzquierda % numero == 0);
		sumaIzquierda += numero;
		return (numero != 0) && (sumaDerecha % numero == 0) && condSumaIzq && aux;
	}
}

bool es_interesante(unsigned int n) {
	// A IMPLEMENTAR
	int sumaDerecha = 0;
	int sumaIzquierda = 0;
	return es_interesante_aux(n, sumaDerecha, sumaIzquierda);
}

void ejecuta_caso() {
	unsigned int n;
	cin >> n;
	if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++) {
		ejecuta_caso();
    }
}