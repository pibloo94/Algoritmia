//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int resuelveCaso(int n) {
	int suma = 0;

	if (n <= 9) {
		cout << n;
		return n;
	}else {
		suma = resuelveCaso(n / 10) + n % 10;
		cout << " + " << n % 10;
		return suma;
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
	int n;
	std::cin >> n;

	// Resolvemos
	while (n >= 0) {
		cout << " = " << resuelveCaso(n) << endl;
		std::cin >> n;
	}
	/*
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif
	*/
	return 0;
}