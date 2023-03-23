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