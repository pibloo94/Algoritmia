//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char preso(vector<char>& v, int ini, int end) {
	char fugado;
	int mitad;

	if (ini + 2 == end) { // en el caso de que haya 2 elementos
		fugado = v[ini] + 1;
	}
	else {
		mitad = (ini + end) / 2;
		if (v[mitad] - v[0] == mitad) { //pivote
			fugado = preso(v, mitad, end);
		}
		else {
			fugado = preso(v, ini, mitad + 1);
		}
	}

	return fugado;
}

char resolver(vector<char>& v, char ini, char end) {
	char fugado;

	if (ini != v[0]) { //en el caso de que falte ini
		fugado = ini;
	}
	else if (end != v[v.size() - 1]) { // en el caso de que falte end
		fugado = end;
	}
	else {
		fugado = preso(v, 0, v.size());

	}

	return fugado;
}

void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	char ini, end, letra;
	std::vector<char> v;

	cin >> ini;
	cin >> end;

	for (int i = 0; i < (end - ini); i++) {
		cin >> letra;
		v.push_back(letra);
	}

	cout << resolver(v, ini, end) << endl;


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