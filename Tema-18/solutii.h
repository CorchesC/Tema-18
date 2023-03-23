#pragma once
#include "functii.h"
using namespace std;

//Exercitiul 1 \/

void sol1() {
	//f) Stergeti linia ce are cel mai rar cifra k in componenta elementelor (k citit de la tastatura).
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	cout << "Introduceti k: " << endl;
	int k;
	cin >> k;
	stergereLinieCuNrCuAparitiiMinimeK(x, m, n,k);
	afisare(x, m, n);
}
void sol2() {
	//g) Sa se stearga linia si coloana elementului cu frecventa maxima.
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	stergereColoanaSiLineCuNrCuFrecMax(x, m, n);
	afisare(x, m, n);
}
void sol3() {
	//h)Stergeti toate liniile ce nu au elementele ordonate (crescator sau descrescator).
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	sterereLiniiNeordonateCrescatorSauDesc(x, m, n);
	afisare(x, m, n);
}