#pragma once
#include "functii.h"
using namespace std;

//Exercitiul 1 \/ (stergeri)

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
	//h) Stergeti toate liniile ce nu au elementele ordonate (crescator sau descrescator).
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	sterereLiniiNeordonateCrescatorSauDesc(x, m, n);
	afisare(x, m, n);
}

//Exercitiul 1 \/ (inserari)

void sol4() {
	//j) Inserati dupa a doua coloana ce contine cel putin un patrat perfect, rasturnatul fiecarui element din aceasta.
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	inserareColoanaSol4(x, m, n);
	afisare(x, m, n);
}
void sol5() {
	//k)Sa se insereze dupa linia cu cele mai multe elemente pare, dublul ei.
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	inserareDublulLineiCuCeleMaiMulteElementePare(x, m, n);
	afisare(x, m, n);
}
void sol6() {
	//n) Inserati dupa linia pe care se gaseste primul element palindrom ce are intre 3 si 5 divizori proprii, dublul ei.
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	inserareLinieSol6(x, m, n);
	afisare(x, m, n);
}

//Exercitul 1 \/ (interschimbare) 

void sol7() {
	//p) Interschimbati prima linie ce are elementele in ordine crescatoare cu urmatoarea linie. In cazul in care nu exista, sortati crescator prima linie si interschimbati - o cu ultima.
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	interschimbareLiniiSol7(x, m, n);
	afisare(x, m, n);
}
void sol8() {
	//q) Interschimbati linia pe care se afla minimul cu linia pe care se afla maximul. Daca elementul minim si maxim se afla pe aceeasi linie, afisati mesajul : "Nu putem interschimba!".
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	interschimbareLiniiCuElementeleMaximeSiMinime(x, m, n);
	afisare(x, m, n);
}
void sol9() {
	// Interschimbati intre ele liniile a.i. prima coloana sa aiba elementele in ordine crescatoare.
	int x[100][100], m = 0, n = 0;
	citire(x, m, n);
	interschimbareLiniiColoanaSortata(x, m, n);
	afisare(x, m, n);
}