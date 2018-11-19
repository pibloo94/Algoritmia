//PABLO AGUDO BRUN  

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


//nota: hacer busqueda binaria

int resolver(vector<int>& v, int ini, int end) {
	int min, mitad;

	if (ini + 1 == end) {
		min = v[ini];
	}else if (ini + 2 == end) {
		if (v[ini] < v[ini + 1]) {
			min = v[ini];
		}else {
			min = v[ini + 1];
		}
	}else{
		mitad = (ini + end) / 2;

		if (v[mitad] < v[mitad + 1] && v[mitad] > v[mitad - 1]) {
			min = resolver(v, ini, mitad);
		}
		else if (v[mitad] > v[mitad + 1] && v[mitad] < v[mitad - 1]) {
			min = resolver(v, mitad, end);
		}
		else {
			min = v[mitad];
		}
	}

	return min;
}


void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	long int l;
	int valor;
	std::vector<int> v;
	std::cin >> l;

	for (long int i = 0; i < l; i++) {
		std::cin >> valor;
		v.push_back(valor);
	}
	
	cout << resolver(v, 0, v.size()) << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
	std: cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}