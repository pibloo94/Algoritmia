//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tCondiciones {
	bool creciente = true;
	bool divertido = true;
};

tCondiciones resolver(vector<int>& v, int nMax) {
	int i = 0, contMax = 1, aux = v[0];

	tCondiciones condicion;

	while (i < v.size() - 1 && (condicion.creciente || condicion.divertido)) {
		if (aux < v[i + 1] && v[i + 1] - aux == 1) {
			aux = v[i + 1];
			contMax = 1;
		}else if (aux == v[i + 1]){
			contMax++;
		}else { // aux > v[i+1]
			condicion.creciente = false;
		}
		
	/*
		}else {
			contMax = 1;
		}
	*/
		if (contMax > nMax) {
			condicion.divertido = false;
		}
		i++;
	}

	return condicion;
}

void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	
	int nMax, nElementos, elemento;
	std::vector<int> v;

	cin >> nMax;
	cin >> nElementos;

	for (int i = 0; i < nElementos; i++) {
		cin >> elemento;
		v.push_back(elemento);
	}
	
	tCondiciones condicionSol = resolver(v, nMax);

	if (condicionSol.creciente && condicionSol.divertido) {
		cout << "SI" << endl;
	}else {
		cout << "NO" << endl;
	}
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
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif
	
	return 0;
}
