
#include <iostream>
#include <fstream>

using namespace std;


int resuelveCaso(int h, int c) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	int tiempo;

	if (h%c == 0) {
		tiempo = (h / c) * 10;
	}else {
		tiempo = ((h / c) + 1) * 10;
	}

	return tiempo;
}

int main() {
	// Para la entrada por fichero.
	/*
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	*/

	int h, c;

	std::cin >> h;
	std::cin >> c;

	// Resolvemos
	while(h != 0 && c!= 0){
		cout << resuelveCaso(h , c) << endl;
		std::cin >> h;
		std::cin >> c;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;

}