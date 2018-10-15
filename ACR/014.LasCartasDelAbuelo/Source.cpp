//PABLO AGUDO BRUN

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//****Time limit exceeded (TLE)****

void resuelveCaso(string &frase, int intervalos) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	long long int min, max, aux;
	bool iguales = true;

	for (int j = 0; j < intervalos; j++) {

		cin >> min;
		cin >> max;
		cin.ignore();

		if (min > max) {
			aux = max;
			max = min;
			min = aux;
		}

		for (int i = min; i <= max; i++) {
			if (frase.at(min) != frase.at(i)) {
				iguales = false;
			}
			cout << i << ": "<< frase.at(i) << " iguales: " << iguales << endl;
		}

		if (iguales) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		iguales = true;
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

	string frase;
	getline(cin, frase);

	//std::vector<char> frase_array(frase.begin(), frase.end());

	long long int intervalos;
	cin >> intervalos;
	cin.ignore();

	// Resolvemos
	while (intervalos != 0) {
		resuelveCaso(frase, intervalos);
		getline(cin, frase);
		cin >> intervalos;
		cin.ignore();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}