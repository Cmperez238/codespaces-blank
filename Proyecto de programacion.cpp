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

        
        vector <char> comp;    // Vector de componentes de cada monomio
        vector <string> mono;  // Vector donde se almacenan los monomios
        p=0;       //Solo tiene un solo uso

        for (auto C : pol)
        {
            p++;
            if (p==1)
            {
                comp.push_back(C);
            }
            else if (p!=1 and (C=='-' or C=='+'))
            {
                string mon(comp.data(), comp.size());                // En este else if se entrara solo si C es + ó -
                mono.push_back(mon);                                 // Una vez adentro se creara un string de cada monomio y se almacenara en el vector mono
                comp.clear();
                comp.push_back(C);
            }
            else if (p==size(pol))
            {
                comp.push_back(C);
                string mon(comp.data(), comp.size());
                mono.push_back(mon);
                comp.clear();
            }
            else
            {
                comp.push_back(C);
            }
        }

        for (string m : mono)
            cout << m << endl;

        

        j++;
    } while (j<=n);

    return 0;
}
