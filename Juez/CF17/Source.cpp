//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
Coste del algoritmo:
	T(n) = {
			Co si n = 1
			T(n/2) + Co si n > 2
			}
	con n = numero de elementos del vector
*/

int resolver(vector<int> const& v, int ini, int end) {
	int min = 0, mitad;

	if (ini + 1 >= end ) { //1 elemento
		if (v[ini] > v[end]) {
			min = v[end];
		}
		else {
			min = v[ini];
		}
	}
	else {
		mitad = (ini + end)/2;
		if (v[ini] > v[mitad]) {
			min = resolver(v, mitad, end);
		}
		else {
			min = resolver(v, ini, mitad);
		}
	}

	return min;
}

void resuelveCaso(int n) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	int valores;
	std::vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> valores;
		v.push_back(valores);
	}

	cout << resolver(v, 0, n-1) << endl;

}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int n;

	// Resolvemos
	while (std::cin >> n) {
		resuelveCaso(n);
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}