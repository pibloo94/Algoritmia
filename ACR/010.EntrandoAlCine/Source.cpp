
#include <iostream>
#include <fstream>

using namespace std;


void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	int nvecinos, cont = 0;
	int lista_butacas[10000];
	bool ordenado = true;

	cin >> nvecinos;

	for (int i = 0; i < nvecinos; i++) {
		cin >> lista_butacas[i];
	}

	int i = 0;
	while (i < nvecinos && lista_butacas[i]%2 == 0) {
		cont++;
		i++;
	}

	while (i < nvecinos) {
		if (lista_butacas[i] % 2 == 0){
			ordenado = false;
		}
		i++;
	}

	if (ordenado) {
		cout << "SI " << cont << endl;
	}
	else {
		cout << "NO" << endl;
	}
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


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;

}