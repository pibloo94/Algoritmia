//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


/*
method problema3 ( a : array <int > , p : int) returns ( b : bool )
requires a != null
requires 0 <= p < a.Length
ensures b == forall u, w :: 0 <= u <= p < w < a.Length == > a[u] < a[w]
*/

//{P: a != null && 0 <= p < a.Length}
void resolver(vector<int>& a, int p) {
	bool b = true;
	int u, w;

	//cout << "p: " << p << endl;

	if (!a.empty() && (0 <= p) && (p < a.size())) {

		u = a.at(0);
		int i;
		for (i = 0; i <= p; i++) {
			if (u < a.at(i)){
				u = a.at(i);
			}
			//cout << "u: " << u << endl;
		}

		for (i; i < a.size(); i++) {
			w = a.at(i);
			if (u >= w) {
				b = false;
			}
			//cout << "w: " << w << endl;
		}
	}

	if (b) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
//{Q: b == forall u, w :: 0 <= u <= p < w < a.Length == > a[u] < a[w]}

void resuelveCaso() {
	std::vector<int> a;
	int nElementos, p, elemento;

	cin >> nElementos;
	cin >> p;

	for (int i = 0; i < nElementos; i++) {
		cin >> elemento;
		a.push_back(elemento);
	}

	resolver(a, p);
}

int main() {

	unsigned int numCasos;
	std::cin >> numCasos;

	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	//system("PAUSE");
	return 0;
}