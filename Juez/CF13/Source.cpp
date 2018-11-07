//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>

using namespace std;

struct sol {
  long int numero;
  long int pot = 0;
};

sol invertir(long int n) {

  sol solucion, aux;

  if (n == 0) {
    solucion.numero = 0;
    solucion.pot = 1;
    return solucion;
  }
  else {
    aux = invertir(n / 10);
    solucion.numero = aux.numero + (n % 10 * aux.pot);
    solucion.pot = aux.pot * 10;
    return solucion;
  }
}

void resuelveCaso(long int n) {
  //resuelve aqui tu caso
     //Lee los datos
     //Calcula el resultado
     //Escribe el resultado

  sol solucion = invertir(n);

  cout << solucion.numero << endl;

}

int main() {
  // Para la entrada por fichero.
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  unsigned long int n;
  // Resolvemos
  while (std::cin >> n) {
    resuelveCaso(n);
  }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}