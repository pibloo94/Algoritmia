//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void resolver(int n, string& solucion) {

	//caso base
	if (n == 0) {
		solucion += "0";
	}
	else if (n == 1){
		solucion += "1";
	}
	//caso recursivo
	else {
		if (n%2 == 0) {
			resolver(n/2, solucion);
			solucion += "0";
		}
		else {
			resolver(n/2, solucion);
			solucion += "1";
		}
	}
}

void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	
	int n;
	string solucion = "";

	std::cin >> n;

	resolver(n, solucion);

	cout << solucion << endl;

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
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}