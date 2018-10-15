
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	string nombre_real, nombre;
	int numero_nietos, cont = 0;

	cin.get();
	cin >> nombre_real;

	cin >> numero_nietos;

	for (int i = 0; i < numero_nietos; i++) {
		cin.get();
		cin >> nombre;

		if (nombre == nombre_real){
			cont++;
		}
	}

	if (nombre.compare(nombre_real) == 0 && numero_nietos > 1 && cont == 1){
		cout << "VERDADERA" << endl;
	}else{
		cout << "FALSA" << endl;
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