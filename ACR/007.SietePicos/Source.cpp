
#include <iostream>
#include <fstream>

using namespace std;
const int N = 1000;


void resuelveCaso(int n) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	int lista_picos[N];
	int pico, cont = 0;

	//guardo las alturas
	for (int i = 0; i < n; i++) {
		cin >> pico;
		lista_picos[i] = pico;
	}

	//comprobamos los casos de en medio
	for (int i = 1; i < n - 1; i++) {
		if (lista_picos[i - 1] < lista_picos[i] && lista_picos[i] >  lista_picos[i + 1]) {
			cont++;
		}
	}

	//comprobamos caso primero
	//si la primera es mayor que la siguiente y que la ultima --> cont ++
	if ((lista_picos[0] > lista_picos[1]) && (lista_picos[n - 1] < lista_picos[0])){
		cont++;
	}

	//comprobamos caso ultimo
	//si la ultima es mayor que la primera y que la anterior --> cont ++
	if ((lista_picos[n - 1] > lista_picos[n - 2]) && (lista_picos[n - 1] > lista_picos[0])){
		cont++;
	}

	cout << cont << endl;
}

int main() {
	// Para la entrada por fichero.
	/*
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	*/

	unsigned int montana_rusa;
	std::cin >> montana_rusa;

	// Resolvemos
	while(montana_rusa != 0){
		resuelveCaso(montana_rusa);
		std::cin >> montana_rusa;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;

}