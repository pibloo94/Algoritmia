//PABLO AGUDO BRUN


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void resuelveCaso(int D, int N) {
	std:vector<int> v;
	int cota, aux;
	bool cumple = true;

	for (int i = 0; i < N; i++) {
		cin >> cota;
		v.push_back(cota);
	}

	aux = v.at(0);
	
	int j = 0;
	while((j < v.size()-1) && cumple){
		if (v.at(j) < v.at(j+1)) {
			if ((v.at(j+1) - aux) > D) {
				cumple = false;
			}
		}
		else if (v.at(j) == v.at(j+1)) {
			if ((v.at(j+1) - aux) > D) {
				cumple = false;
			}
			aux = v.at(j + 1);
		}
		else {
			if (v.at(j) > v.at(j+1)) {
				if((v.at(j) - aux) > D){
					cumple = false;
				}
			}
			aux = v.at(j + 1);
		}
		j++;
	}

	if (cumple) {
		cout << "APTA" << endl;
	}else {
		cout << "NO APTA" << endl;
	}
}

int main() {

	int D, N;
	
	// Resolvemos
	while (std::cin >> D) {
		std::cin >> N;
		resuelveCaso(D,N);
	}

	return 0;
}