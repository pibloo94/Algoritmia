
#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {
	cout << "Hola mundo.\n";
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
	while (numCasos < 0 || numCasos > 5) {
		std::cin >> numCasos;
	}
	
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;

}