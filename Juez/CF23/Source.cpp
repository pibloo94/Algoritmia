//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string elegirColor(vector<int>& solucion, int& i) {
	string x;

	switch (solucion[i]) {
	case 0:
		x = "azul";
		break;
	case 1:
		x = "rojo";
		break;
	case 2:
		x = "verde";
		break;
	}

	return x;
}

void tratarSolucion(std::vector<int>& solucion, int& n) {
	bool cumple = true;
	string x;

	for (int i = 0; i < n; i++) {
		x = elegirColor(solucion, i);

		if(cumple){
			cout << x;
			cumple = false;
		}
		else {
			cout << " " << x;
		}
	}

	cout << endl;
}

bool esValida(std::vector<int>& solucion, int& k) {
	bool cumple = true;

	for (int i = 0; i < k && cumple; i++) {
		if ((solucion[i] == 2) && (solucion[i + 1] == 2)) {
			cumple = false;
		}
	}

	return cumple;
}

void resolver(
	std::vector<int>& colores,
	std::vector<int>& solucion,
	std::vector<int>& contColores,
	std::vector<bool>& marcaje,
	int k, int& n, bool& exito) {

	for (int i = 0; i < 3; i++) {
		if (!marcaje[i]) {
			solucion[k] = i;
			contColores[i]++;

			if (contColores[i] == colores[i]) {
				marcaje[i] = true;
			}

			if (contColores[2] <= contColores[0] && esValida(solucion, k)) { // nºpiezas verdes no supera al nºpiezas azules
				if (k == n - 1) { // k = longitud de la torre
					if (contColores[0] + contColores[2] < contColores[1]) { // nºpiezas rojas siempre mayor que nºpiezas (azules + verdes)
						tratarSolucion(solucion, n);
						exito = true;
					}
				}else {
					resolver(colores, solucion, contColores, marcaje, k + 1, n, exito);
				}
			}

			contColores[i]--;
			marcaje[i] = false;
		}
	}
}

bool resuelveCaso() {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	int n, color;
	bool exito = false;

	cin >> n;

	if (!std::cin)
		return false;

	std::vector<int> colores(3);
	std::vector<int> solucion(n);
	std::vector<int> contColores(3, 0);
	std::vector<bool> marcaje(3, false);

	for (int i = 0; i < 3; i++) {
		cin >> colores[i];
	}

	if (colores[0] == 0 && colores[1] == 0 && colores[2] == 0) {
		return false;
	}

	if (colores[1] == 0) {
		cout << "SIN SOLUCION" << endl;
	}
	else {
		solucion[0] = 1;
		contColores[1]++;

		if (contColores[1] == colores[1]) {
			marcaje[1] = true;
		}

		if (n >= 2) {
			resolver(colores, solucion, contColores, marcaje, 1, n, exito);
		}
	}

	if (!exito) {
		cout << "SIN SOLUCION" << endl;
	}

	cout << endl;

	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

