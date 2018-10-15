
#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso(int muestras) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	long long int valores, aux= 0;
	bool creciente = true;

	for (int i = 0; i < muestras; i++) {
		cin >> valores;
		if (valores <= aux){
			creciente = false;
		}
		else {
			aux = valores;
		}
	}

	if (creciente){
		cout << "SI" << endl;
	}else {
		cout << "NO" << endl;
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

	unsigned int muestras;
	std::cin >> muestras;

	// Resolvemos
	while (muestras != 0) {
		resuelveCaso(muestras);
		std::cin >> muestras;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}