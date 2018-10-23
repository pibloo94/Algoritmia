//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


/*
{P: 0 < v.Length <= 1000 && forall k:: 0 <= k < v.Length ==> -50 <= v[k] <= 60}
fun picos(v: array<int>) returns(contPicos: int)
{Q: contPicos = #u: 0 <= z < v.Length-1: v[u-1] < v[u] > v[u+1)}
*/ 
int picos(vector<int>& v) {
	int contPicos = 0;
	//{I: 1 <= i < v.size()}
	//{I: contPicos = #u: forall k: 1 <= k < n-1: a[k] > a[k+1] && a[k] > a[k-1]}
	for (int i = 1; i < v.size() - 1; i++) {
		if (v.at(i - 1) < v.at(i) && v.at(i + 1) < v.at(i)) {
			contPicos++;
		}
	}
	return contPicos;
}

/*
{P: 0 < v.Length <= 1000 && forall k:: 0 <= k < v.Length ==> -50 <= v[k] <= 60}
fun valles(v: array<int>) returns(contValles: int)
{Q: contValles = #u: 0 <= z < v.Length-1: v[u-1] > v[u] < v[u+1)}
*/ 
int valles(vector<int>& v) {
	int contValles = 0;
	//{I: 1 <= i < v.size()}
	//{I: contValles = #u: forall k: 1 <= k < n-1: a[k] < a[k+1] && a[k] < a[k-1]}
	for (int i = 1; i < v.size() - 1; i++) {
		if (v.at(i - 1) > v.at(i) && v.at(i + 1) > v.at(i)) {
			contValles++;
		}
	}
	return contValles;
}

/*
void resuelveCaso(int v[], int n, int& nPicos, int& nValles)
*/
void resuelveCaso() {

	std::vector<int> v;
	int ntemp, temperaturas;

	cin >> ntemp;

	for (int i = 0; i < ntemp; i++) {
		cin >> temperaturas;
		v.push_back(temperaturas);
	}

	cout << picos(v) << " " << valles(v) << endl;
}

int main() {
	// Para la entrada por fichero.

	unsigned int numCasos;
	std::cin >> numCasos;

	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	
	return 0;
}
