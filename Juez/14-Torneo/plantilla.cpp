
#include <iostream>

using namespace std;


/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

(4) An�lisis de la complejidad del algoritmo

*/
int min_poder(int enemigos[], int n, int max_duelos) {
	// Punto de entrada al algoritmo: a implementar
}


const int MAX_ENEMIGOS = 1000;
bool ejecuta_caso() {
	int enemigos[MAX_ENEMIGOS];
	int num_enemigos;
	cin >> num_enemigos;
	if (num_enemigos == -1) {
		return false;
	}
	else {
		int max_torneos;
		cin >> max_torneos;
		for (int i = 0; i < num_enemigos; i++) {
			cin >> enemigos[i];
		}
		cout << min_poder(enemigos, num_enemigos, max_torneos) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}
