#include <iostream> 
#include <vector>
#include <sstream>

using namespace std;

struct tPolinomio
{ 
	int grado;                /* Grado del polinomio */
    vector<double> coef;      /* Coeficientes */
};

int main () {

    int n, i, j {1};
    string equt;
    stringstream ss;
    cout << "Introduzca la cantidad de polinomios a sumar: ";
    cin >> n;
    cin.ignore();

    for (i=1; i<=n; i++)
        tPolinomio poli[i];

    do{
    cout << endl << "Polinomio " << j << " :";
    getline (cin, equt);
    equt << ss;

    for (auto equt : ss)
        cout << equt << endl;

    j++;
    } while (j<=n);

    return 0;
}
