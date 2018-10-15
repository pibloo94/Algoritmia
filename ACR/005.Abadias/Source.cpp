
#include <iostream>
#include <fstream>

using namespace std;


void resuelveCaso(int cordillera) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	int altura, cont = 1, max;
	int montanas[100000];

	for (int i = 0; i < cordillera; i++) {
		cin >> altura;
		montanas[i] = altura;
	}

	max = montanas[cordillera - 1];

	for (int j = cordillera; j > 0; j--) {
		if (max < montanas[j - 1]) {
			max = montanas[j - 1];
			cont++;
		}
	}
	cout << cont << endl;

}

int main() {
	// Para la entrada por fichero.
	/*
	#ifndef DOMJUDGE
	  std::ifstream in("casos.txt");
	  auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	*/

	int cordillera;
	std::cin >> cordillera;
	// Resolvemos
	while (cordillera > 0 && cordillera <= 100000) {
		resuelveCaso(cordillera);
		std::cin >> cordillera;
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;

}