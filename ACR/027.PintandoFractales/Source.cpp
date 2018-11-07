//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>

using namespace std;

int resolver(long int n) {
	long int tinta = 0;

	if (n == 1) {
		tinta = 4;
	}
	else {
		tinta = resolver(n / 2) * 4 + n*4;
	}

	return tinta;
}

void resuelveCaso(long int n) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	cout << resolver(n) << endl;
}

int main() {
	// Para la entrada por fichero.
	
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	long int n;

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