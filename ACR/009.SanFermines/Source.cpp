
#include <iostream>

#include <fstream>
using namespace std;

bool resuelveCaso(int n) {

	//Leer caso de prueba
	int vtoro, vcorredor = 0;

	for (int i = 0; i < n; i ++) {
		cin >> vtoro;
		if (vtoro > vcorredor) {
			vcorredor = vtoro;
		}
	}

	cout << vcorredor << endl;

	//Resolver problema
	//Escribir resultado
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
	/*
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	*/
	int ntoros;

	while (std::cin >> ntoros) {
		resuelveCaso(ntoros);
	}

	return 0;
}