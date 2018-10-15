
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


int main() {
	// Para la entrada por fichero.
	/*
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	*/

	int pisoIni, piso, aux, cont;

	// Resolvemos
	while (cin >> pisoIni && pisoIni >= 0){
		aux = pisoIni;
		cont = 0;
		while (cin >> piso && piso != -1) {
			/*
			if (aux > piso){
				cont = cont + (aux - piso);
				aux = piso;
			}else if (aux < piso) {
				cont = cont + (piso - aux);
				aux = piso;
			}
			*/
			cont += abs(piso - aux);
			aux = piso;

			//cout << "contador: " << cont << endl;
		}
		cout << cont << endl;
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;

}