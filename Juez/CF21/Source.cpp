//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {
	int suma = 0;
	bool cumple = true;
};

/*
Analisis y justificacion del coste:
	
	T(n) = {
			C0 si n = 2
			2*T(n/2) + cte si n > 2
			}

			con n = numero de elementos

Justificacion del coste:
	con a = 2, b = 2 y k = 0 estamos en el caso; a > b^k, es decir, 2 > 1
	por lo tanto el coste del algoritmo es O(n^(log(b)a)) = O(n^(log(2)2)) = O(n)

*/
tSolucion resolver(std::vector<int> const& v, int ini, int end, tSolucion& sol) {
	int mitad;
	tSolucion solIzq, solDer;

	//caso base
	if (ini + 1 == end) { // 2 elementos
		if (v[ini] < v[ini + 1]) {
			sol.cumple = true;
			sol.suma = v[ini] + v[ini + 1];
		}
		else {
			sol.cumple = false;
		}
	}
	//caso recursivo
	else {
		mitad = (ini + end) / 2;

		solIzq = resolver(v, ini, mitad, sol); // parte izq de la imagen
		solDer = resolver(v, mitad + 1, end, sol); // parte der de la imagen

		if (solIzq.cumple && solDer.cumple) {
			if (solIzq.suma < solDer.suma) {
				sol.cumple = true;
			}
			else {
				sol.cumple = false;
			}
		}
	}

	return sol;
}

bool resuelveCaso() {

	int n, m; //n = filas, m = columnas

	std::cin >> n;
	std::cin >> m;

	if (!std::cin) {
		return false;
	}

	int i = 0, cont = 0;
	tSolucion sol;

	while (i < n) {
		std::vector<int> v(m);

		for (int j = 0; j < m; j++) {
			std::cin >> v[j];
		}

		resolver(v, 0, v.size() - 1, sol);

		if (sol.cumple) {
			cont ++;
		}

		i++;
	}

	if (cont == n) {
		std::cout << "SI" << endl;
	}
	else {
		std::cout << "NO" << endl;
	}

	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}