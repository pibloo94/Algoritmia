
#include <iostream>
#include <fstream>
using namespace std;

int resolverFactorial(int n) {
	int factorial = 1;

	if (n <= 4) {
		for (int i = 1; i <= n; i++) {
			factorial = factorial * i;
		}
		factorial = factorial % 10;
	}else {
		factorial = 0;
	}
	return factorial;
}

void resuelveCaso() {
	int x;
	cin >> x;
	cout << resolverFactorial(x) << endl;
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