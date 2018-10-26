//PABLO AGUDO BRUN


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int resolver(vector<int>& v) {
	int i = 0, j = v.size() - 1, pos = 0, aux;

	while (i < v.size()) {
		if (v[i] < 0) {
			while (v[j] < 0 && j > 0 && i < j) {
				j--;
			}
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
		i++;
	}

	int x = 0;
	while (x < v.size() && v[x] >= 0) {
		x++;
	}

	return x;
}

void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	std:vector<int> v;
	int n, elemento;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> elemento;
		v.push_back(elemento);
	}

	cout << resolver(v) << endl;
}

int main() {
	// Para la entrada por fichero.
	
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	
	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif
	
	return 0;
}