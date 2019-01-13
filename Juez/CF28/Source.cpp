//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {
	int inicio = 0;
	int ganancia = 0;
};

tSolucion resolver(std::vector<int>& v, int& t, tSolucion& sol) {
	int sum;

	for (int i = 0; i < t; i ++) {
		sol.ganancia += v[i];
	}

	sum = sol.ganancia;

	for (int i = 1; i < v.size() - t + 1; i++) {
		sum = sum - v[i - 1];
		sum = sum + v[i + t - 1];

		if (sum >= sol.ganancia) {
			sol.ganancia = sum;
			sol.inicio = i;
		}
	}

	return sol;
}

void resuelveCaso() {

	int n, t;

	std::cin >> n;
	std::cin >> t;

	std::vector<int> v(n);
	tSolucion sol;

	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	resolver(v, t, sol);

	cout << sol.inicio << " " << sol.ganancia << endl;
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