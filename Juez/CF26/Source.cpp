//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void tratarSolucion(std::vector <int>& solucion, int const& k) {
	for (int i = 0; i <= k; i++) {
		cout << solucion[i] << " ";
	}

	cout << endl;
}

bool esValida(std::vector<int> const& consumos,
	std::vector<int>& solucion,
	std::vector<int>& marcaje, 
	int const& k, int const& n, int const& nColores,
	int const& consumoMax, int const& consumoAct, 
	int const& contBombillas, int const& i) {

	if (consumoAct <= consumoMax) {
		if (marcaje[i] <= k + 1 + 1 - marcaje[i]) { // en todo momento el numero de luces de un color solo puede superar en 1 al resto
			if (k >= 2) { // si mi longitud de mi solucion posible es >= 2
				if (solucion[k - 1] == solucion[k] && solucion[k - 2] == solucion[k]) { //si tengo 3 bombillas del mismo tipo iguales
					return false;
				}
				else {
					return true;
				}
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void resolver(std::vector<int> const& consumos, 
	std::vector<int>& solucion,
	std::vector<int>& marcaje,
	int k, int const& n, int const& nColores, 
	int& consumoMax, int& consumoAct, int& contBombillas) {
	
	for (int i = 0; i < nColores; i ++) {
		solucion[k] = i;
		consumoAct += consumos[i]; //calculo el nuevo consumo
		marcaje[i] ++; //aumento el numero de bombillas en este momento de tipo i

		if (esValida(consumos, solucion, marcaje, k, n, nColores, consumoMax, consumoAct, contBombillas, i)) {
			if (k == n - 1) {
				//tratarSolucion(solucion, k);
				contBombillas++;
			}
			else {
				resolver(consumos, solucion, marcaje, k + 1, n, nColores, consumoMax, consumoAct, contBombillas);
			}
		}

		consumoAct -= consumos[i];
		marcaje[i] --;
	}
}

bool resuelveCaso() {

	int n, nColores, consumoMax;

	std::cin >> n >> nColores >> consumoMax;

	if (!std::cin) {
		return false;
	}

	std::vector<int> consumos(nColores); // consumo por cada tipo de bombilla
	std::vector<int> solucion(n);
	std::vector<int> marcaje(nColores, 0); // numero de bombillas de cada tipo en cada momento

	int consumoAct = 0, contBombillas = 0;

	for (int i = 0; i < nColores; i ++) {
		std::cin >> consumos[i];
	}

	resolver(consumos, solucion, marcaje, 0, n, nColores, consumoMax, consumoAct, contBombillas);

	/*if (contBombillas == 0) {
		std::cout << "SIN SOLUCION" << endl;
	}
	else {*/
		std::cout << contBombillas << endl;
	//}

	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while(resuelveCaso());	

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}