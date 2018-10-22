//PABLO AGUDO BRUN	

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int posMax(vector<int>& v) {
	int max = 0;

	if(!v.empty()){
		max = v.at(0);
		for (int i = 1; i < v.size(); i++) {
			if (max < v.at(i)) {
				max = v.at(i);
			}
		}
	}
	return max;
}

int sumSinMaximo(vector<int>& v) {
	int suma = 0, i = 0;
	int max = posMax(v);

	if (!v.empty() && max != 0) {
		while (i < v.size()){
			if (v.at(i) != max) {
				suma += v.at(i);
			}
			i++;
		}
	}

	return suma;
}

// Coste lineal en funcion de v.Length: O(n)
void resuelveCaso() {
	std::vector<int> v;
	int n, elemento;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> elemento;
		v.push_back(elemento);
	}

	cout << sumSinMaximo(v) << endl;
}

int main() {
	// Para la entrada por fichero.

	unsigned int numCasos;
	std::cin >> numCasos;

	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	return 0;
}