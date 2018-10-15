
#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	long long int aux, min, contmin, max, contmax;

	std::cin >> aux;

	min = aux, contmin = 1, max = aux, contmax = 1;

	while (std::cin >> aux && aux != 0) {
		if (aux > max) {
			max = aux;
			contmax = 1;
		}
		else if (aux == max) {
			contmax++;
		}

		if (aux < min) {
			min = aux;
			contmin = 1;
		}
		else if (aux == min) {
			contmin++;
		}
	}

	cout << min << " " << contmin << " " << max << " " << contmax << endl;

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