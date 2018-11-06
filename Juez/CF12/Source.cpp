//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos{
	int maxSeq = 0;
	int iniSeq = 0;
	int longSeq = 1;
};

tDatos resuelve(vector<int>& v) {
	tDatos datos;
	tDatos auxDatos;

	int i = 0;

	/*
	invariant 0 <=  i <= n
	invariant forall
	decreases n-i
	*/
	while (i < v.size()) {
		auxDatos.maxSeq += v[i];
		if (auxDatos.maxSeq > 0) {
			auxDatos.longSeq = i + 1 - auxDatos.iniSeq;
			if (auxDatos.maxSeq > datos.maxSeq) {
				datos.maxSeq = auxDatos.maxSeq;
				datos.iniSeq = auxDatos.iniSeq;
				datos.longSeq = auxDatos.longSeq;
			}
			else if (auxDatos.maxSeq == datos.maxSeq) {
				if (auxDatos.longSeq < datos.longSeq) {
					datos.longSeq = auxDatos.longSeq;
					datos.iniSeq = i - auxDatos.longSeq + 1;
				}
			}
		}
		else { // auxDatos.maxSeq <= 0
			auxDatos.maxSeq = 0;
			auxDatos.iniSeq = i + 1;
		}
		i++;
	}

	return datos;
}

void resuelveCaso(int n) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	std:vector<int> v;
	int valor;

	for (int i = 0; i < n; i++) {
		cin >> valor;
		v.push_back(valor);
	}
	 tDatos datos = resuelve(v);

	 cout << datos.maxSeq << " " << datos.iniSeq << " " << datos.longSeq << endl;
}

int main() {
	// Para la entrada por fichero.
	
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	unsigned int n;

	// Resolvemos
	while (std::cin >> n) {
		resuelveCaso(n);
	}

	
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	
	return 0;
}
