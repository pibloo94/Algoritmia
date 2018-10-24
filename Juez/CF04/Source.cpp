//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
{P: 0 < v.Length && forall k:: 0 <= k < v.Length ==> v[k] > 0}
method resolver(v: array<int>, max: int, min: int, t: int)
{Q: max = #u: 0 <= u < v.Length: v[u] > t} //bien?
*/
void resolver(vector<int> &v, int &max, int &min, int &t) {

	int i = 0, contmax = 0, contmin = 0;

	//{I: 0 <= i < v.Length}
	//{I: contmin = #u: forall k: 0 <= k < v.Length: v[k] > t}
	//{I: contmax = #w: forall k: 0 <= k < v.Length: v[k] > t}
	while (i < v.size()) {
		if (v.at(i) > t){
			contmin++;
		}else {
			contmin = 0;
		}

		if (contmax < contmin) {
			min = i + 1 - contmin;
			max = i;
			contmax = contmin;
		}
		i++;
	}

	cout << min << " " << max << endl;
}

void resuelveCaso() {

	int n, t, altura, min = 0, max = 0;
	std::vector<int> v;

	cin >> n;
	cin >> t;

	for (int i = 0; i < n; i++) {
		cin >> altura;
		v.push_back(altura);
	}

	resolver(v, min, max, t);

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