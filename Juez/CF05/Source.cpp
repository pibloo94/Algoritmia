//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
int numUnos(vector<int> v) {
  int nUnos;
  if (v.empty()){
    nUnos = 0;
  }else {
    if (v.at(0) == 1) {
      v.erase(v.begin());
      nUnos = 1 + numUnos(v);
    }else {
      nUnos = numUnos(v);
    }
  }
  return nUnos;
}
*/

/*
int numCeros(vector<int> v) {
  int nCeros;
  if (v.empty()) {
    nCeros = 0;
  }else{
    if (v.at(0) == 1) {
      v.erase(v.begin());
      nCeros = 1 + numCeros(v);
    }else {
      nCeros = numCeros(v);
    }
  }
  return nCeros;
}
*/

//Coste lineal: O(n) en funcion de v.Length
int xxx(vector<int> v) {
  int p = -1, i = 0, nCeros = 0, nUnos = 0;

  while (i < v.size()) {
    if (v.at(i) == 0){
      nCeros++;
    }else {
      if (v.at(i) == 1) {
        nUnos++;
      }
    }

    if (nCeros == nUnos) {
      p = i;
    }
    i++;
  }
  return p;
}

void resuelveCaso() {
  std::vector<int> v;
  int tamVector, valores;

  cin >> tamVector;

  for (int i = 0; i < tamVector; i++) {
    cin >> valores;
    v.push_back(valores);
  }

  cout << xxx(v) << endl;
}

int main() {
  // Para la entrada por fichero.

  unsigned int numCasos;
  std::cin >> numCasos;

  // Resolvemos
  for (int i = 0; i < numCasos; ++i) {
    resuelveCaso();
  }

  //system("PAUSE");
  return 0;
}