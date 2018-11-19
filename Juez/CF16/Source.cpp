//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {
	int tachado = -1;
	bool encontrado = false;
};

tSolucion resolver(vector<int>& v, int cantado, int ini, int end){
	int mitad = (ini + end) / 2;
	tSolucion solucion;

	//caso base
	if (ini + 1 == end) {
		if (ini + cantado == v[ini]) {
			solucion.tachado = v[ini];
			solucion.encontrado = true;
		}
	}
	//caso base
	else if (cantado + mitad == v[mitad]) {
		solucion.tachado = v[mitad];
		solucion.encontrado = true;
	}
	else if (v[mitad] > mitad + cantado) {
		solucion = resolver(v, cantado, ini, mitad);
	}
	else if (v[mitad] < mitad + cantado) {
		solucion = resolver(v, cantado, mitad, end);
	}

	return solucion;
}

void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	int n, cantado, valores;
	std::vector<int> v;

	cin >> n;
	cin >> cantado;

	for (int i = 0; i < n; i++) {
		cin >> valores;
		v.push_back(valores);
	}

	tSolucion solucion = resolver(v, cantado, 0, v.size());

	if (solucion.encontrado) {
		cout << solucion.tachado << endl;
	}
	else {
		cout << "NO" << endl;
	}
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