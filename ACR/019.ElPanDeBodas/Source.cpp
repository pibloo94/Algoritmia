
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resuelveCaso(int sillas) {
	std::vector<char> v;
	char estado;
	bool comenDer = true, comenIzq = true;

	for (int i = 0; i < sillas; i++) {
		cin >> estado;
		v.push_back(estado);
	}

	for (int i = 0; i < v.size() && (comenDer || comenIzq); i++) {
		if (v.at(i) == 'D'){
			comenDer = false;
		}else if (v.at(i) == 'I' ) {
			comenIzq = false;
		}
	}

	if (!comenDer && !comenIzq) {
		cout << "ALGUNO NO COME" << endl;
	}else {
		cout << "TODOS COMEN" << endl;

	}
}

int main() {

	unsigned int sillas;
	std::cin >> sillas;

	// Resolvemos
	while (sillas != 0) {
		resuelveCaso(sillas);
		std::cin >> sillas;
	}
	
	//system("PAUSE");

	return 0;
}