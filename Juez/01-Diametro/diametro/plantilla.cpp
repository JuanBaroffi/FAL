/*
Nº GRUPO:
NOMBRES Y APELLIDOS: Juan Israel Baroffi González
*/


#include <iostream>
#include <climits>

using namespace std;


//n siempre será positivo (es decir, podéis asumir n >= 1)
int diametro(int a[], int n) {
	 // A IMPLEMENTAR
	int max = INT_MIN, i = 0, min = INT_MAX;
	while (i < n)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}
		i++;
	}
	return max - min;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

const int TMAX = 1000000;  // No se podrán leer vectores de más de un millón de elementos

bool ejecuta_caso() {
	static int a[TMAX];
	int n;
	cin >> n;
	if (n == -1 || n > TMAX) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << diametro(a, n) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}