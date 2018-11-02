//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int>& v) {
	int maxPartidos = 0, nVeces = 0, nPartidos = 0;
	int maxPartidosAux = 0, racha = 0, i = 0;

	while (i < v.size()) {
		if (v.at(i) > 0) {
			maxPartidosAux++;
			if (maxPartidosAux > maxPartidos){
				maxPartidos = maxPartidosAux;
				nPartidos = i + 1;
				nVeces = 1;
			}else if (maxPartidosAux == maxPartidos) {
				nPartidos = i + 1;
				nVeces++;
			}
		}else {
			maxPartidosAux = 0;
		}
		i++;
	}

	racha = v.size() - nPartidos;

	cout << maxPartidos<< " " << nVeces << " " << racha << endl;
}

void resuelveCaso(int n) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	std::vector<int> v;
	int elemento;

	for (int i = 0; i < n; i++) {
		cin >> elemento;
		v.push_back(elemento);
	}

	resolver(v);

}

int main() {
	// Para la entrada por fichero.

	/*
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	*/
	int n;

	// Resolvemos
	while (std::cin >> n) {
		resuelveCaso(n);
	}

	/*
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif
	*/

	return 0;
}