
#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	long long int muros;
	long long int alturaIni, altura, aux = 0, contArriba = 0, contAbajo = 0;

	cin >> muros;
	cin >> alturaIni;

	aux = alturaIni;
	for (long long int i = 1; i < muros; i++) {
		cin >> altura;

		if (altura > aux) {
			contArriba++;
			aux = altura;
		}

		else if (altura < aux){
			contAbajo++;
			aux = altura;
		}
	}

	cout << contArriba << " " << contAbajo << endl;
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