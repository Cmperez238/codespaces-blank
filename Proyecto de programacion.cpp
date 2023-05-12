#include <iostream> 
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct tPolinomio
{ 
	int grado;                /* Grado del polinomio */
    vector <double> coef;      /* Coeficientes */
};

struct tExponentes
{     
    vector <int> expo;                // Contiene los exponentes del polinomio, mientras que el que contiene los coeficientes es coef.
};



int main () {

    int n, i, j;
    char C;
    string equt;
    vector <char> vec;
    cout << "Introduzca la cantidad de polinomios a sumar: ";
    cin >> n;
    cin.ignore();

    vector <tPolinomio> poli(n);
    vector <tExponentes> exponentes(n);
    vector <int> grados;

    for (i=0; i<n; i++)
    {
            poli[i].coef;
            poli[i].grado = 0;

            cout << endl << "Polinomio " << i+1 << " :";
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
            j=0;

            for (auto C : rawpol)
            {
                j++;
                if (not(j==1 and (C=='+')))
                {
                    vec.push_back(C);
                }
            }

            string pol(vec.data(), vec.size()); //Este nuevo string no contiene un mas al inicio en caso de que contenga uno
            vec.clear();

            
            // Vector de componentes de cada monomio, se almacenara en vec
            vector <string> rawmono;  // Vector donde se almacenan los monomios
            j=0;       //Solo tiene un solo uso

            for (auto C : pol)
            {
                j++;
                if (j!=1 and (C=='-' or C=='+'))
                {
                    string mon(vec.data(), vec.size());                // En este else if se entrara solo si C es + ó -
                    rawmono.push_back(mon);                                 // Una vez adentro se creara un string de cada monomio y se almacenara en el vector mono
                    vec.clear();
                    vec.push_back(C);
                }
                else if (j==size(pol))
                {
                    vec.push_back(C);
                    string mon(vec.data(), vec.size());
                    rawmono.push_back(mon);
                    vec.clear();
                }
                else
                {
                    vec.push_back(C);
                }
            }

            vector <string> mono;
            string rmon;

            for (auto rmon : rawmono)
            {
                j=0;
                for (auto C : rmon)
                {
                    j++;
                    if (not(C=='+') and j!=size(rmon))
                    {
                        vec.push_back(C);
                    }
                    else if (j==size(rmon))
                    {
                        vec.push_back(C);
                        string monomio(vec.data(), vec.size());
                        vec.clear();
                        mono.push_back(monomio);
                    }
                }
            }

            vector <string> trash;
            string nulo = "cero";

            for (auto rmon : mono)
            {
                stringstream ss;
                ss << rmon;
                double num;
                string salto;
                ss >> num >> salto;
                poli[i].coef.push_back(num);
                if (salto.empty())
                    trash.push_back(nulo);
                else
                    trash.push_back(salto);
            }

            
            for (auto salto : trash)
            {
                if (salto==nulo)
                {
                    j=0;
                    exponentes[i].expo.push_back(j);
                }
                else
                {
                    stringstream ss;
                    ss << salto;
                    int expon;
                    char t, s;
                    ss >> t >> s >> expon;
                    exponentes[i].expo.push_back(expon);
                }
            }

            int m=exponentes[i].expo.size();

            for (j = 0; j < m - 1; j++) {        //Le pedi a chatgpt que nos ayudara corriegiendo el algoritmo porque no cambiaba ningun elemento
                for (int k = j + 1; k < m; k++) {
                    if (exponentes[i].expo.at(j) > exponentes[i].expo.at(k)) {
                        int temp1 = exponentes[i].expo.at(j);
                        double temp2 = poli[i].coef.at(j);
                        exponentes[i].expo.at(j) = exponentes[i].expo.at(k);
                        poli[i].coef.at(j) = poli[i].coef.at(k);
                        exponentes[i].expo.at(k) = temp1;
                        poli[i].coef.at(k) = temp2;
                    }
                }
            }

            // //Finalmente definimos el grado de la funcion
            poli[i].grado=exponentes[i].expo.at(m-1);
            grados.push_back(poli[i].grado);

            for (j = 0; j < m - 1; j++)
            {
                for (int k = j+1; k < m; k++)
                {
                    if (exponentes[i].expo.at(j) == exponentes[i].expo.at(k))  //He pedido ayuda a Chatgtp corrigiendo el programa que busca loe lelementos repeitos en el vector
                    {
                        double temp2 = poli[i].coef.at(j) + poli[i].coef.at(k);
                        poli[i].coef.at(j) = temp2;
                        exponentes[i].expo.erase(exponentes[i].expo.begin() + k);
                        poli[i].coef.erase(poli[i].coef.begin()+ k);
                        m--;
                        k--;
                    }
                }
            }
    }

    //Ahora tenemos cada coeficiente dentro de vectores y cada grado, aplicamos el algoritmo de la burbuja para encontrar el mayor grado de los polinomios
    for (i=0; i<n-1; i++) {
        for (j = i + 1; j < n ; j++) {
            if (grados.at(i) < grados.at(j)) {
                int temp1 = grados.at(i);
                grados.at(i) = grados.at(j);
                grados.at(j) = temp1;
            }
        }
    }

    int m=grados.at(0);
    int v=0;

    for (i=0; i<n; i++)  //ChatGTP ayudo corrigiendo esta parte del codigo
    {
        int size = exponentes[i].expo.size(); // obtener el tamaño actual del vector
        for (j=0; j<size; j++) // iterar hasta el tamaño actual del vector
        {

            if (exponentes[i].expo.at(j)==j)
            {
                // No hacer nada
            }
            else if (exponentes[i].expo.at(j)!=j)
            {
                exponentes[i].expo.insert(exponentes[i].expo.begin() + j, j);
                poli[i].coef.insert(poli[i].coef.begin() + j, v);
                size++; // incrementar el tamaño del vector después de la inserción
            }
        }   
    }

    for (i=0; i<n; i++) //Se puede acortar mucho mas el codigo
    {
        exponentes[i].expo.resize(m+1);
        poli[i].coef.resize(m+1);
        for (j=0; j<=m; j++)
        {
            if (exponentes[i].expo.at(j)==j)
            {
                // No hacer nada
            }
            else if (exponentes[i].expo.at(j)!=j)
            {
                exponentes[i].expo.at(j)=j;
                poli[i].coef.at(j)=0;
            }
        }
    }


    vector <double> coeffinal(m+1);
    coeffinal=poli[0].coef;

    for (i=1; i<n; i++)
    {
        for (j=0; j<=m; j++)
            coeffinal.at(j)=coeffinal.at(j)+poli[i].coef.at(j); 
    }

    i=0;
    for (auto temp2 : coeffinal)
    {
        if(i!=0 and temp2>0)
        {
            cout << "+" << temp2 << "*x" << i ;
        }
        else if(i!=0 and temp2<0)
        {
            cout << temp2 << "*x" << i;
        } 
        else if (i==0)
            cout << temp2;
        i++;
    }
            

    return 0;
}
