
#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	int administracion, decimo, cont = 0;

	cin >> administracion;

	for (int i = 0; i < administracion; i++) {
		cin >> decimo;
		if (decimo%2 == 0){
			cont++;
		}
	}

	cout << cont << endl;
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