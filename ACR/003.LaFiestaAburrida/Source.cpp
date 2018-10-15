
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	string str1;

	cin.get();
	getline(cin, str1);

	int pos = str1.find(" ");
	string str2 = str1.substr(pos, str1.size());

	cout << "Hola," << str2 << "." << endl;
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