#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void citire(int x[100][100], int& m, int& n) {
	ifstream f("numere.txt");
	f >> m;
	f >> n;
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			f >> x[i][j];
		}
	}
}
void afisare(int x[100][100], int& m, int& n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}
void stergereLinie(int x[100][100], int& m, int n, int l) {
	for (int i = l; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = x[i + 1][j];
		}
	}
	m--;
}
int nrAparitiiKInNr(int n, int k) {
	int nr = 0;
	while (n != 0) {
		int c = n % 10;
		if (c == k) {
			nr++;
		}
		n = n / 10;
	}
	return nr;
}
void stergereLinieCuNrCuAparitiiMinimeK(int x[100][100], int& m, int n, int k) {
	int min = 999999;
	int poz = -1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int nr = nrAparitiiKInNr(x[i][j], k);
			if (nr < min) {
				min = nr;
				poz = i;
			}
		}
	}
	if (poz >= 0) {
		stergereLinie(x, m, n, poz);
	}
}
void stergereColoana(int x[100][100], int m, int& n, int c) {
	for (int j = c; j < n - 1; j++) {
		for (int i = 0; i < m; i++) {
			x[i][j] = x[i][j + 1];
		}
	}
	n--;
}
int frecventaElement(int x[100][100], int m, int n, int e) {
	int fr = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i][j] == e) {
				fr++;
			}
		}
	}
	return fr;
}
void stergereColoanaSiLineCuNrCuFrecMax(int x[100][100], int& m, int& n) {
	int max = -1;
	int pozL = -1;
	int pozC = -1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int fr = frecventaElement(x, m, n,x[i][j]);
			if (fr > max) {
				max = fr;
				pozL = i;
				pozC = j;
			}

		}
	}
	if (pozL >= 0 && pozC >= 0) {
		stergereLinie(x, m, n, pozL);
		stergereColoana(x, m, n, pozC); 
	}
}
bool esteLiniaOrdonataCrescator(int x[100][100], int m, int n, int l) {
	bool aff = false;
	for (int j = 0; j < n-1; j++) {
		if (x[l][j] < x[l][j + 1]) {
			aff == true;
		}
		else {
			return false;
		}
	}
	return aff;
}
bool esteLiniaOrdonataDescrescator(int x[100][100], int m, int n, int l) {
	bool aff = false;
	for (int j = 0; j < n - 1; j++) {
		if (x[l][j] > x[l][j + 1]) {
			aff == true;
		}
		else {
			return false;
		}
	}
	return aff;
}
void sterereLiniiNeordonateCrescatorSauDesc(int x[100][100], int& m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (esteLiniaOrdonataCrescator(x, m, n, i) == false || esteLiniaOrdonataDescrescator(x, m, n, i) == false) {
				stergereLinie(x, m, n, i);
			}
		}
	}
}
void inserareColoana(int x[100][100], int m, int& n, int c, int v[]) {
	for (int j = n - 1; j >= c; j--) {
		for (int i = 0; i < m; i++) {
 			x[i][j + 1] = x[i][j];
		}
	}
	n++;
	for (int i = 0; i < m; i++) {
		x[i][c] = v[i];
	}
}
int oglindit(int n) {
	int ogl = 0;
	while (n != 0) {
		int cf = n % 10;
		ogl = ogl * 10 + cf;
		n = n / 10;
	}
	return ogl;
}
void vectorDinRasturnatulElementelorUneiColoane(int x[100][100], int m, int n, int c, int v[], int& d) {
	for (int i = 0; i < m; i++) {
		v[d] = oglindit(x[i][c]);
		d++;
	}
}
bool patratPerfect(int n) {
	if ((int)sqrt(n) == sqrt(n)) {
		return true;
	}
	else {
		return false;
	}
}
bool coloanaContinePatratPerfect(int x[100][100], int m, int n,int c) {
	for (int i = 0; i < m; i++) {
			if (patratPerfect(x[i][c]) == true) {
				return true;
			}
	}
	return false;
}
void afisareVector(int v[], int dim) {
	for (int i = 0; i < dim; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
void inserareColoanaSol4(int x[100][100], int m, int& n) {
	int cnt = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (coloanaContinePatratPerfect(x, m, n, j) == true && cnt == 2) {
				int v[100], d = 0;
				vectorDinRasturnatulElementelorUneiColoane(x, m, n, j, v, d);
				inserareColoana(x, m, n, j, v);
			}
			else if(coloanaContinePatratPerfect(x, m, n, j) == true && cnt != 2){
				cnt++;
			}
		}
	}
}
void inserareLinie(int x[100][100], int& m, int n, int l, int v[]) {
	for (int i = m - 1; i >= l; i--) {
		for (int j = 0; j < n; j++) {
			x[i + 1][j] = x[i][j];
		}
	}
	m++;
	for (int j = 0; j < n; j++) {
		x[l][j] = v[j];
	}
}
void dublulLinieiSubFormaDeVector(int x[100][100], int m, int n, int l, int v[]) {
	int d = 0;
	for (int j = 0; j < n; j++) {
		v[d] = 2 * x[l][j];
		d++;
	}
}
void inserareDublulLineiCuCeleMaiMulteElementePare(int x[100][100], int& m, int n) {
	int max = 0;
	int pozMax = -1;
	for (int i = 0; i < m; i++) {
		int nrP = 0;
		for (int j = 0; j < n; j++) {
			if (x[i][j] % 2 == 0) {
				nrP++;
			}
		}
		if (nrP > max) {
			max = nrP;
			pozMax = i;
		}
	}
	int v[100];
	dublulLinieiSubFormaDeVector(x, m, n, pozMax, v);
	inserareLinie(x, m, n, pozMax+1, v);
}
bool palindrom(int n) {
	int ogl = oglindit(n);
	if (n == ogl) {
		return true;
	}
	else {
		return false;
	}
}
int nrDivizoriPropii(int n) {
	int nrD = 0;
	for (int x = 1; x <= n; x++) {
		if (x != 1 && x != n) {
			if (n % x == 0) {
				nrD++;
			}
		}
	} 
	return nrD;
}
void inserareLinieSol6(int x[100][100], int& m, int n) {
	int cst = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (palindrom(x[i][j]) == true && cst == 1 && nrDivizoriPropii(x[i][j] >= 3) && nrDivizoriPropii(x[i][j] <= 5)) {
				int v[100];
				dublulLinieiSubFormaDeVector(x, m, n, i,v);
				inserareLinie(x, m, n, i + 1, v);
			}
		}
	}
}
void interschimbareLinii(int x[100][100], int m, int n, int l1, int l2) {
	for (int j = 0; j < n; j++) {
		int aux = x[l1][j];
		x[l1][j] = x[l2][j];
		x[l2][j] = aux;
	}
}
void linieSubFormaDeVector(int x[100][100], int m, int n, int l,int v[],int& d) {
	for (int j = 0; j < n; j++) {
		v[d] = x[l][j];
		d++;
	}
}
void bubbleSort(int v[], int dim) {
	bool aff = true;
	do {
		aff = true;
		for (int j = 0; j < dim - 1; j++) {
			if (v[j] > v[j + 1]) {
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				aff = false;
			}
		}
	} while (aff == false);
}
void schimbareLinie(int x[100][100], int& m, int n, int l, int v[], int d){
	int dim = 0;
	for (int j = 0; j < n && dim < d; j++) {
		x[l][j] = v[dim];
		dim++;
	}
}
void interschimbareLiniiSol7(int x[100][100], int& m, int n) {
	bool aff = false;
	for (int i = 0; i < m; i++) {
		if (esteLiniaOrdonataCrescator(x, m, n, i) == true) {
			aff == true;
			interschimbareLinii(x, m, n, i, i + 1);
		}
	}
	if (aff == false) {
		int v[100], d = 0;
		linieSubFormaDeVector(x, m, n, 0, v,d);
		bubbleSort(v, d);
		schimbareLinie(x, m, n, 0, v, d);
		interschimbareLinii(x, m, n, 0, m - 1);
	}
}
int liniaCuElementulMaxim(int x[100][100], int m, int n) {
	int max = -1;
	int lMax = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i][j] > max) {
				max = x[i][j];
				lMax = i;
			}
		}
	}
	return lMax;
}
int liniaCuElementulMinim(int x[100][100], int m, int n) {
	int min = 99999999;
	int lMin = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i][j] < min) {
				min = x[i][j];
				lMin= i;
			}
		}
	}
	return lMin;
}
void interschimbareLiniiCuElementeleMaximeSiMinime(int x[100][100], int m, int n) {
	int lMax = liniaCuElementulMaxim(x, m, n);
	int lMin = liniaCuElementulMinim(x, m, n);
	if (lMax != lMin) {
		interschimbareLinii(x, m, n, lMax, lMin);
	}
	else if (lMax == lMin) {
		cout << "Nu putem interschimba!" << endl;
	}
}
void interschimbareLiniiColoanaSortata(int x[100][100], int m, int n) {
	for (int i = 0; i < m-1; i++) {
		if (x[i][0] > x[i + 1][0]) {
			interschimbareLinii(x, m, n, i, i + 1);
		}
	}
}