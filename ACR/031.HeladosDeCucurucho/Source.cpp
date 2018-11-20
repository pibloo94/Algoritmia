///PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void resolver(int chocolate, int vainilla, bool& primero, string combinacion) {

	if (chocolate == 0 && vainilla == 0) {
		if (primero) {
			cout << combinacion;
			primero = false;
		}
		else {
			cout << " " << combinacion;
		}
	}
	
	if (chocolate > 0) {
		 resolver(chocolate - 1, vainilla, primero, combinacion + "C");
	}
	 
	if (vainilla > 0) {
		resolver(chocolate, vainilla - 1, primero,combinacion + "V");
	}

}

void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	int chocolate, vainilla;
	bool primero = true;
	string combinacion;

	std::cin >> chocolate;
	std::cin >> vainilla;

	resolver(chocolate, vainilla, primero, combinacion);

	cout << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}