//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;


bool esValida(
	std::vector<bool>& marcaje,
	std::vector<int>& comprados, 
	int& i, int& k) {

	if (comprados[i] < 3 ) {
		return true;
	}
	else {
		return false;
	}
}

void resolver(
	std::vector<std::vector<int>>& precios,
	std::vector<int>& comprados,
	std::vector<bool>& marcaje,
	std::vector<int> preciosMinProd,
	std::vector<int> mejoresAcum,
	int k, int& numSupers,
	int& sum, int& sol) {

	for (int i = 0; i < numSupers; i++) {
		if(!marcaje[k]){
			if (esValida(marcaje, comprados, i, k)) {
				sum += precios[i][k]; // se recalcula el precio de la compra
				comprados[i] ++; //se aumento el contador de productos comprados en el super i
				marcaje[k] = true; //se marca el producto como comprado

				if (k == marcaje.size() - 1) {
					if (sum < sol) {
						sol = sum;
					}
				}
				else {
					if (mejoresAcum[k + 1] + sum < sol) {
						resolver(precios, comprados, marcaje, preciosMinProd, mejoresAcum, k + 1, numSupers, sum, sol);
					}
				}

				//si no es una solucion, restauramos datos
				sum -= precios[i][k];
				comprados[i] --;
				marcaje[k] = false;
			}
		}
	}
}

void resuelveCaso() {

	int numSupers, numProd;

	std::cin >> numSupers >> numProd;

	std::vector<std::vector<int>> precios(numSupers, std::vector<int> (numProd)); //matriz de precios
	std::vector<int> comprados(numSupers, 0); //numero productos comprados por cada supermercado
	std::vector<bool> marcaje(numProd, false); //marcaje para saber si se ha comprado ya el producto
	std::vector<int> preciosMinProd(numProd, INT_MAX); //precios minimos de cada producto
	std::vector<int> mejoresAcum(numProd); //mejor precio acumulado de productos

	int sum = 0, sol = INT_MAX;

	for (int i = 0; i < numSupers; i++) {
		for (int j = 0; j < numProd; j++) {
			std::cin >> precios[i][j];

			//si el precio de un producto es el minimo 
			if (precios[i][j] < preciosMinProd[j]) {
				preciosMinProd[j] = precios[i][j];
			}
		}
	}

	mejoresAcum[numProd - 1] = preciosMinProd[numProd - 1];

	//relleno el vector con las mejores acumulaciones
	for (int i = numProd - 2; i >= 0; i--) {
		mejoresAcum[i] = mejoresAcum[i + 1] + preciosMinProd[i];
	}

	resolver(precios, comprados, marcaje, preciosMinProd, mejoresAcum, 0, numSupers, sum, sol);

	std::cout << sol << endl;
}

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	unsigned int n;
	std::cin >> n;

	// Resolvemos
	for (int i = 0; i < n; ++i) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}