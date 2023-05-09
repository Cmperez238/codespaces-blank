#include <iostream> 
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct tPolinomio
{ 
	int grado;                /* Grado del polinomio */
    vector<double> coef;      /* Coeficientes */
};

int main () {

    int n, i, j {1};
    char C;
    string equt;
    stringstream ss;
    vector <char> vec;
    cout << "Introduzca la cantidad de polinomios a sumar: ";
    cin >> n;
    cin.ignore();

    for (i=1; i<=n; i++)
        tPolinomio poli[i];

    int m;

    do{
        cout << endl << "Polinomio " << j << " :";
        getline (cin, equt);
        
        for (auto C : equt) // Copia en C cada char de equt y va analizando si es un espacio (Usamos chatGTP para conocer de isspace)
        {
            if (not (isspace(C)))
            {
                vec.push_back(C);
            }
        }

        string rawpol(vec.data(), vec.size());  // Este nuevo string simplemente abra ignorado todos los espacios que el usuario ha insertado
        vec.clear();
        int p{0};

        for (auto C : rawpol)
        {
            p++;
            if (not(p==1 and (C=='+')))
            {
                vec.push_back(C);
            }
        }

        string pol(vec.data(), vec.size()); //Este nuevo string no contiene un mas al inicio en caso de que contenga uno
        vec.clear();

        do {  // Esta parte sigue inconclusa
        ss << pol;
        double num;
        ss >> num;

        int k{0};   // Lo que hace el entero es contar la posicion del ss, este va a viajar siempre entre doubles
        k++;
        if (k % 2 != 0)
        {
            coef.push_back(num);
        }

        } while () 

        

    j++;
    } while (j<=n);

    return 0;
}
