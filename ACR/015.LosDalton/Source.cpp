//PABLO AGUDO BRUN


#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso(int vineta) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	long long int altura, aux, cont1 = 1, cont2 = 1;
	bool sondalton = true;

	cin >> altura;
	aux = altura;

	for (int i = 0; i < vineta - 1 ; i++) {
		cin >> altura;

		if (aux > altura && sondalton && cont1 == 1){
			aux = altura;
			cont2 = 0;
		}
		else if(aux < altura && sondalton && cont2 == 1) {
			aux = altura;
			cont1 = 0;
		}
		else {
			sondalton = false;
		}
	}

	if (sondalton){
		cout << "DALTON" << endl;
	}else {
		cout << "DESCONOCIDOS" << endl;
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

	unsigned int vineta;
	std::cin >> vineta;
	// Resolvemos
	while(vineta != 0){
		resuelveCaso(vineta);
		std::cin >> vineta;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}