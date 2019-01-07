
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;


void resolver(std::vector<std::vector<int>> const& v,
	std::vector<bool>& marcaje,
	int k, int const& n, int& sumMin, int& sum, int const& constante) {

	for (int i = 0; i < n; i++) {

		if (!marcaje[i]) {
			sum += v[i][k];
			marcaje[i] = true; // marcaje

			if (k == n - 1) {
				if (sum < sumMin) {
					sumMin = sum;
				}
			}
			else { // no ccompruebo de que no haya hueco, por lo tanto haya o no hueco lo va a comprobar
				   // por esta razon es la poda peor ya que analiza todos los casos
				resolver(v, marcaje, k + 1, n, sumMin, sum, constante);			
			}
			marcaje[i] = false; // desmarcaje
			sum -= v[i][k];
		}
	}
}

bool resuelveCaso() {

	int n, sum = 0, sumMin;
	int constante = INT_MAX;

	std::cin >> n; // numero de funcionarios y trabajos

	if (n == 0) {
		return false;
	}

	std::vector<std::vector<int>> v(n, std::vector<int>(n)); //matriz de tiempos
	std::vector<bool> marcaje(n, false); //vector marcaje inicializada a false

	//relleno la matriz
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> v[i][j];
			if (v[i][j] < constante) {
				constante = v[i][j];
			}
		}
	}

	sumMin = INT_MAX;

	resolver(v, marcaje, 0, n, sumMin, sum, constante);

	std::cout << sumMin << endl;

	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}