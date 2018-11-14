//PABLO AGUDO BRUN  

#include <iostream>
#include <fstream>

using namespace std;

struct tBalanceado {
	bool balanceadoDer = true;
	bool balanceadoIzq = true;
};

bool resolver(int& pi, int& di, int& pd, int& dd) {
	tBalanceado balanceado;
	int piAux, diAux, pdAux, ddAux;

	if (pi == 0) {
		std::cin >> piAux >> diAux >> pdAux >> ddAux;
		balanceado.balanceadoIzq = resolver(piAux, diAux, pdAux, ddAux);
		pi = piAux + pdAux;
	}

	if (pd == 0) {
		std::cin >> piAux >> diAux >> pdAux >> ddAux;
		balanceado.balanceadoDer = resolver(piAux, diAux, pdAux, ddAux);
		pd = pdAux + piAux;
	}
		
	return balanceado.balanceadoDer && balanceado.balanceadoIzq && (pi*di == pd*dd);
}

void resuelveCaso(int pi, int di, int pd, int dd) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	if (resolver(pi, di, pd, dd)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int pi, di, pd, dd;
	std::cin >> pi >> di >> pd >> dd;

	// Resolvemos
	while (pi != 0 || di != 0 || pd != 0 || dd != 0) {
		resuelveCaso(pi, di, pd, dd);
		std::cin >> pi >> di >> pd >> dd;
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}