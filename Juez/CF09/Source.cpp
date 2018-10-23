//PABLO AGUDO BRUN

//NOTA: reordenar primero pares y luego pares y redimensionalizar con .resize(n)

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool estricCreciente(vector<int>& v) {
	bool creciente = true;

	if (!v.empty()) {

		int i = 0;
		while (i < v.size() - 1 && creciente) {
			if ((v.at(i) == 0) || (v.at(i) >= v.at(i + 1))) {
				creciente = false;
			}
			i++;
		}
	}
	return creciente;
}

void resolver(vector<int>& v) {


	if (estricCreciente) {

		int i = 0, par = 0, n = v.size();
		while (i < n) {
			if (v[i] % 2 == 0) {
				v.at(par) = v.at(i);
				par++;
			}
			i++;
		}
		v.resize(par);
	}
	
	for (int j = 0; j < v.size(); j++) {
		cout << v.at(j) << " ";
	}

	cout << endl;
}

void resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	std::vector<int> v;
	int n, valor;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	resolver(v);

}

int main() {
	// Para la entrada por fichero.

	unsigned int numCasos;
	std::cin >> numCasos;

	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	system("PAUSE");

	return 0;
}