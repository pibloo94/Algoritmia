
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

//funcion que devuelve un vector de acumulacion de los tiempos minimos por cada funcionario
std::vector<int> acumulados(std::vector<std::vector<int>> const& v, int& n) {
	std::vector<int> minimos(n);
	int minFila;

	for (int i = 0; i < v.size(); i++) {
		minFila = v[0][i];
		for (int j = 1; j < n; j++) {
			if (v[j][i] < minFila) {
				minFila = v[j][i];
			}
		}
		minimos[i] = minFila;
	}

	//acumulos los tiempos minimos de cada funcionario
	std::vector<int> estimacion (n);
	estimacion[n - 1] = minimos[n - 1];

	for (int i = v.size() - 2; i >= 0; i--) {
		estimacion[i] = estimacion[i + 1] + minimos[i];
	}

	return estimacion;
}

void resolver(std::vector<std::vector<int>> const& v, 
	std::vector<bool>& marcaje,
	std::vector<int>& acumulados,
	int k, int& n, int& sumMin, int& sum) {

	for (int i = 0; i < n; i++) {

		if (!marcaje[i]) {
			sum += v[i][k];
			marcaje[i] = true; // marcaje

			if (k == n - 1) {
				if (sum < sumMin) {
					sumMin = sum;
				}
			}
			else {
				if (sum + acumulados[k + 1] < sumMin) {
				resolver(v, marcaje, acumulados, k + 1, n, sumMin, sum);
				}
			}
			marcaje[i] = false; // desmarcaje
			sum -= v[i][k];
		}
	}
}

bool resuelveCaso() {

	int n, sum = 0, sumMin;
	
	std::cin >> n; // numero de funcionarios y trabajos

	if (n == 0) {
		return false;
	}

	std::vector<std::vector<int>> v(n, std::vector<int>(n)); //matriz de tiempos
	std::vector<bool> marcaje (n, false); //vector marcaje inicializada a false
	std::vector<int> acumulado;

	//relleno la matriz
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> v[i][j];
		}
	}

	acumulado = acumulados(v, n);
	sumMin = INT_MAX;

	resolver(v, marcaje, acumulado, 0, n, sumMin, sum);

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