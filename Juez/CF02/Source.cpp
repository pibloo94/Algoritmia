//PABLO AGUDO BRUN


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


//{P: true}
int colones(vector<int>& v) {
	int cont = 0, aux;
	//{I: 0 < i <= v.size()-1}
	//{I: cont = #k: forall u: v.size() > u > 0: v[u] < v[u-1] && aux = exists w: v.size() > u >= w > 0: v[u] > v[w] ==> w = u}
	if(!v.empty()){
		aux = v.at(v.size() - 1);
		for (int i = v.size() - 1; i > 0; i--) {
			if (aux < v.at(i-1)){
				cont++;
			}

			if (aux > v.at(i-1)) {
				aux = v.at(i - 1);
			}
		}
	}

	return cont;
}
//{Q: cont = #k: forall u: v.size() > u > 0: v[u] < v[u-1] && exists w: v.size() > u >= w > 0: v[u] > v[w] ==> w = u}

void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	int nlista, numero;
	std::vector<int> v;

	cin >> nlista;
	
	for (int i = 0; i < nlista; i++) {
		cin >> numero;
		v.push_back(numero);
	}

	cout << colones(v) << endl;
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

	/*
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif
	*/
	return 0;
}