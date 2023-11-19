#include <iostream>
#include <algorithm>
using namespace std;


/*
(1) Precondición

(2) Postcondición

(3) Si vas a utilizar una generalización, especificación
    pre-pos de la generalización
	
(4) Casos no recursivos

(5) Casos recursivos

(6) Terminación (expresión de cota)

(7) Si has usado una generalización, definición por
    inmersión de es_paracurioso

(8) Determinación de la complejidad (recurrencias y su resolución)

	
*/

typedef struct {
	bool curioso;
	int nP;
	int nI;
	int sumP;
	int sumI;
}tSol;

tSol es_parcurioso_aux(int v[], int ini, int fin) {
	int nP = 0;
	int nI = 0;
	int sumP = 0;
	int sumI = 0;
	bool curioso = false;

	if ((fin - ini) <= 0)
	{
		if (v[ini] % 2 == 0)
		{
			nP++;
			sumP = v[ini];
		}
		else {
			nI++;
			sumI = v[ini];
		}
		return { true,nP,nI,sumP,sumI };
	}
	else {
		tSol pMitad, sMitad;
		int medio = (fin + ini) / 2;
		if (true)
		{

		}
		pMitad = es_parcurioso_aux(v, ini, medio);
		sMitad = es_parcurioso_aux(v, medio + 1, fin);
		curioso = (pMitad.nP <= sMitad.nI && pMitad.sumP <= sMitad.sumI) && (pMitad.curioso || sMitad.curioso);

		nP = pMitad.nP + sMitad.nP;
		nI = pMitad.nI + sMitad.nI;
		sumP = pMitad.sumP + sMitad.sumP;
		sumI = pMitad.sumI + sMitad.sumI;

		return { curioso, nP, nI, sumP, sumI };
	}
}

bool /* resul*/ es_parcurioso(int v[], int n) {
	// A IMPLEMENTAR
	return es_parcurioso_aux(v, 0, n - 1).curioso;
}


// NO MODIFICAR

const static int MAX_ELEMENTS = 100000;

void ejecuta_caso() {
		static int v[MAX_ELEMENTS];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (es_parcurioso(v, n)) {
			cout << "SI" << endl;;
		}
		else {
			cout << "NO" << endl;
		}
}


int main() {
	int n;
	cin >> n;
	for (int i=0; i < n; i++)
	  ejecuta_caso();
	return 0;
}