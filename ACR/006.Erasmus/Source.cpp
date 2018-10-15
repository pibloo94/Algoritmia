
#include <iostream>
#include <fstream>

using namespace std;


int factorial(int n) {
	long long int factorial = 1;

	for (int i = 1; i <= n; i++) {
		factorial *= i;
	}

	return factorial;
}

void resuelveCaso(int paises) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	long long int estudiantes, parejas, aux = 0, total = 0;

	for (int i = 0; i < paises; i++) {
		cin >> estudiantes;
		total += estudiantes;
		if (estudiantes > 1) {
			aux += (factorial(estudiantes) / (factorial(2) * factorial(estudiantes - 2)));
		}
	}

	parejas = factorial(total) / (factorial(2) * factorial(total - 2));

	cout << parejas - aux << endl;
}

int main() {
	// Para la entrada por fichero.
	/*
	#ifndef DOMJUDGE
	  std::ifstream in("casos.txt");
	  auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	*/

	int paises;
	std::cin >> paises;
	// Resolvemos
	while (paises > 0 && paises <= 100000) {
		resuelveCaso(paises);
		std::cin >> paises;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;

}