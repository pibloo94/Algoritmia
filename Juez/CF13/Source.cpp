//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>

using namespace std;

struct sol {
  long long int numero = 0;
  long long int pot = 1;
};

//{P: 0 <= n <= (2^31)-1}
sol invertir(long int n) {

  sol solucion;

  if (n != 0) {
	solucion = invertir(n / 10);
	solucion.numero += (n % 10 * solucion.pot);
	solucion.pot = solucion.pot * 10;
  }

  return solucion;
}
//{Q: solucion = invertir(n/10)}

void resuelveCaso(long long int n) {
  //resuelve aqui tu caso
     //Lee los datos
     //Calcula el resultado
     //Escribe el resultado

  sol solucion = invertir(n);

  cout << solucion.numero << endl;

}

int main() {
  // Para la entrada por fichero.

  /*
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  */
  long long int n;
  // Resolvemos
  while (std::cin >> n) {
    resuelveCaso(n);
  }
  /*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  */
  return 0;
}