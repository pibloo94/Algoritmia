//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
Precondicion:
	v != null
	ordenado(v,ini,end);
	hayUnImpar(v);

	ordenado(v,ini,end) == forall ini,end :: 0 <= ini <= end < v.size() ==> v[ini] < v[end]
	hayUnImpar(v) == forall k :: 0 <= k < v.size() ==> exists v[k]%2 != 0
*/
int resolver(vector<int> const& v, int ini, int end) {
	int imp, mitad, imp1, imp2;

	if (ini == end) { // 1 elemento
		imp = v[ini];
	}
	else if (ini + 1 == end) { // 2 elementos
		if (v[ini] % 2 != 0) {
			imp = v[ini];
		}
		else {
			imp = v[end];
		}
	}
	else { // n elementos
		mitad = (ini + end) / 2;
		
		if (v[mitad] % 2 != 0) { // compruebo si mitad es el impar
			imp = v[mitad];
		}
		else { // recorro derecha e izquierda del vector
			imp1 = resolver(v, ini, mitad);
			imp2 = resolver(v, mitad, end);

			if (imp1 % 2 != 0) {
				imp = imp1;
			}
			else {
				imp = imp2;
			}
		}
	}

	return imp;
}

/*
Postcondicion:
	imp%2 != 0
*/

void resuelveCaso(int n) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	int valores;
	std::vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> valores;
		v.push_back(valores);
	}

	cout << resolver(v, 0, v.size()-1) << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int n;
	std::cin >> n;
	
	// Resolvemos
	while (n != 0) {
		resuelveCaso(n);
		std::cin >> n;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}