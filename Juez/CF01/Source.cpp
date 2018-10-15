//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//{P: true}
int picos(vector<int>& v) {
	int contPicos = 0;
	//{I: 1 <= i < v.size()}
	//{I: contPicos = #u: forall k: 1 <= k < n-1: a[k] > a[k+1] && a[k] > a[k-1]}
	for (int i = 1; i < v.size() - 1; i++) {
		if (v.at(i - 1) < v.at(i) && v.at(i + 1) < v.at(i)) {
			contPicos++;
		}
	}
	return contPicos;
}
//{Q: contPicos = #u: forall k: 1 <= k < n-1: a[k] > a[k+1] && a[k] > a[k-1]}

//{P: true}
int valles(vector<int>& v) {
	int contValles = 0;
	//{I: 1 <= i < v.size()}
	//{I: contValles = #u: forall k: 1 <= k < n-1: a[k] < a[k+1] && a[k] < a[k-1]}
	for (int i = 1; i < v.size() - 1; i++) {
		if (v.at(i - 1) > v.at(i) && v.at(i + 1) > v.at(i)) {
			contValles++;
		}
	}
	return contValles;
}
//{Q: contValles = #u: forall k: 1 <= k < n-1: a[k] < a[k+1] && a[k] < a[k-1]}

void resuelveCaso() {

	std::vector<int> v;
	int ntemp, temperaturas;

	cin >> ntemp;

	for (int i = 0; i < ntemp; i++) {
		cin >> temperaturas;
		v.push_back(temperaturas);
	}

	cout << picos(v) << " " << valles(v) << endl;
}

int main() {
	// Para la entrada por fichero.

	/*
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	*/

	unsigned int numCasos;
	std::cin >> numCasos;

	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	/*
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	*/

	return 0;
}