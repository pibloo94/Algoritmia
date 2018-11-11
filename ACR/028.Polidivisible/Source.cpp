//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>

using namespace std;

bool resolver(long long int n, int& cont) {

	int aux;
	bool polidivisible = true;

	if (n < 10) {
		aux = n % cont;
	
	}else {
		polidivisible = resolver(n/10 , cont);
		cont++;
		aux = n % cont;
	}

	if (aux != 0) {
		polidivisible = false;
	}

	return polidivisible;
}

void resuelveCaso(long long int& n) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	int cont = 1;

	if (resolver(n, cont)) {
		cout << "POLIDIVISIBLE" << endl;
	}
	else {
		cout << "NO POLIDIVISIBLE" << endl;
	}
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	long long int n;

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