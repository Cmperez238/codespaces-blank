#include <iostream> 
#include <vector>
#include <sstream>
#include <string>

using namespace std;

//Le pedi a chatgpt que nos ayudara corriegiendo el algoritmo porque no cambiaba ningun elemento, linea 129
//He pedido ayuda a Chatgtp corrigiendo el programa que busca los lelementos repeitos en el vector, linea 152, igual solo ayudo en correcion
//ChatGTP ayudo corrigiendo el codigo de la linea 177

struct tPolinomio
{ 
	int grado;                /* Grado del polinomio */
    vector <double> coef;      /* Coeficientes */
};

struct tExponentes
{     
    vector <int> expo;       // Contiene los exponentes del polinomio, mientras que el que contiene los coeficientes es coef.
};

void burbuja(int* vec, int n);

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
        getline(cin, equt);

        vector<char> vec; // Vector de caracteres utilizado para ignorar espacios
        for (auto C : equt) {
            if (not (isspace(C))) {
                vec.push_back(C);
            }
        }
        string rawpol(vec.data(), vec.size()); // Se crea un nuevo string sin espacios

        vec.clear(); // Se limpia el vector de caracteres para ser utilizado en el siguiente loop

        vector<string> rawmono; // Vector donde se almacenarán los monomios
        int j = 0;
        for (auto C : rawpol) {
            j++;
            if (j != 1 and (C == '-' or C == '+')) {
                string mon(vec.data(), vec.size()); // Se crea un nuevo string para almacenar cada monomio
                rawmono.push_back(mon); // Se añade el monomio al vector de monomios
                vec.clear(); // Se limpia el vector de caracteres para el siguiente monomio
                vec.push_back(C); // Se añade el signo del siguiente monomio al vector de caracteres
            }
            else if (j == rawpol.size()) {
                vec.push_back(C); // Se añade el último caracter al vector de caracteres
                string mon(vec.data(), vec.size()); // Se crea un nuevo string para almacenar el último monomio
                rawmono.push_back(mon); // Se añade el último monomio al vector de monomios
                vec.clear(); // Se limpia el vector de caracteres
            }
            else {
                vec.push_back(C); // Se añade el caracter actual al vector de caracteres
            }
        }

        vector <string> mono; // Se crea un vector de strings para almacenar los monomios
        string rmon; // Variable para almacenar un monomio de manera temporal

        for (auto rmon : rawmono) { // Se itera sobre cada elemento del vector rawmono
            j=0;
            for (auto C : rmon) { // Se itera sobre cada caracter del monomio actual
                j++;
                if (not(C=='+') and j!=size(rmon)) { // Si el caracter actual no es '+' y no es el ultimo caracter del monomio, se agrega al vector vec
                    vec.push_back(C);
                }
                else if (j==size(rmon)) { // Si el caracter actual es el ultimo caracter del monomio, se agrega al vector vec y se crea un string monomio con vec
                    vec.push_back(C);
                    string monomio(vec.data(), vec.size()); // Se crea un string con los caracteres del vector vec
                    vec.clear(); // Se limpia el vector vec
                    mono.push_back(monomio); // Se agrega el monomio al vector mono
                }
            }
        }

        vector <string> trash; // Se crea un vector de strings para almacenar elementos no deseados
        string nulo = "cero"; // Se crea un string con el valor "cero"

        for (auto rmon : mono) { // Se itera sobre cada elemento del vector mono
            stringstream ss;
            ss << rmon; // Se guarda el monomio actual en un stringstream
            double num; // Variable temporal para almacenar el coeficiente del monomio actual
            string salto; // Variable temporal para almacenar el resto del monomio actual
            ss >> num >> salto; // Se extrae el coeficiente y el resto del monomio actual
            if(num!=0){ // Si el coeficiente no es cero
                poli[i].coef.push_back(num); // Se agrega el coeficiente al vector de coeficientes del polinomio i-esimo
                if (salto.empty()) // Si el resto del monomio es vacío
                    trash.push_back(nulo); // Se agrega "cero" al vector trash
                else
                    trash.push_back(salto); // Se agrega el resto del monomio al vector trash
            }
        }

        
        for (auto salto : trash) {         // Itera sobre los elementos del vector trash
            if (salto==nulo) {                  // Si el elemento es "cero"
                j=0;
                exponentes[i].expo.push_back(j); // Agrega 0 al vector de exponentes del polinomio i
            }
            else {
                stringstream ss;
                ss << salto;
                int expon;
                char t, s;
                ss >> t >> s >> expon;          // Extrae el exponente del string "salto"
                exponentes[i].expo.push_back(expon); // Agrega el exponente al vector de exponentes del polinomio i
            }
        }

        int m=exponentes[i].expo.size();

        for (j = 0; j < m - 1; j++) {          // Ordena los exponentes y coeficientes del polinomio i de menor a mayor
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


        //Finalmente definimos el grado de la funcion
        poli[i].grado=exponentes[i].expo.at(m-1);
        grados.push_back(poli[i].grado);

        // Fusionamos los monomios con el mismo exponente
        for (j = 0; j < m - 1; j++) {
            for (int k = j+1; k < m; k++) {
                if (exponentes[i].expo.at(j) == exponentes[i].expo.at(k))  
                {
                    // Sumamos los coeficientes y lo asignamos al primer coeficiente
                    double temp2 = poli[i].coef.at(j) + poli[i].coef.at(k);
                    poli[i].coef.at(j) = temp2;

                    // Eliminamos el segundo coeficiente y exponente
                    exponentes[i].expo.erase(exponentes[i].expo.begin() + k);
                    poli[i].coef.erase(poli[i].coef.begin()+ k);
                    m--;
                    k--;
                }
            }
        }

    } // Aqui finaliza el primer for

    //Ahora tenemos cada coeficiente dentro de vectores y cada grado, aplicamos el algoritmo de la burbuja para encontrar el mayor grado de los polinomios
    burbuja (&grados[0], n); //Llamamos a la funcion que ordena los exponentes de mayor a menor

    int m=grados.at(0);
    int v=0;

    for (i=0; i<n; i++) { // iterar sobre todos los polinomios
        int size = exponentes[i].expo.size(); // obtener el tamaño actual del vector
        for (j=0; j<size; j++) { // iterar hasta el tamaño actual del vector
            if (exponentes[i].expo.at(j)!=j) { // verificar si el elemento faltante es el siguiente exponente esperado
                exponentes[i].expo.insert(exponentes[i].expo.begin() + j, j); // insertar el exponente faltante
                poli[i].coef.insert(poli[i].coef.begin() + j, v); // insertar el coeficiente faltante
                size++; // incrementar el tamaño del vector después de la inserción
            }
        }   
    }


    for (i=0; i<n; i++) {                       //Itera sobre cada polinomio en la matriz de polinomios
        exponentes[i].expo.resize(m+1);         //Ajusta el tamaño del vector de exponentes del polinomio a m+1
        poli[i].coef.resize(m+1);               //Ajusta el tamaño del vector de coeficientes del polinomio a m+1
        for (j=0; j<=m; j++) {                  //Itera sobre cada termino del polinomio
            if (exponentes[i].expo.at(j)!=j) {  //Si el exponente no es igual al índice del término
                exponentes[i].expo.at(j)=j;     //Asigna el exponente igual al índice del término
                poli[i].coef.at(j)=0;           //Asigna un coeficiente de cero al término
            }
        }
    }

    vector <double> coeffinal(m+1);      //Declara un vector de coeficientes finales de tamaño m+1
    coeffinal=poli[0].coef;              //Copia los coeficientes del primer polinomio en el vector coeffinal

    for (i=1; i<n; i++) {                //Itera sobre los polinomios restantes
        for (j=0; j<=m; j++)             //Itera sobre cada término del polinomio
            coeffinal.at(j)=coeffinal.at(j)+poli[i].coef.at(j); //Agrega el coeficiente del término a coeffinal
    }

    cout << endl << "El polinomio suma es de grado " << m << ":" << endl; //Muestra el grado del polinomio suma
    i=0;
    for (auto temp2 : coeffinal) {       //Itera sobre cada coeficiente en coeffinal
        if(i!=0 and temp2>0) {           //Si el exponente no es cero y el coeficiente es positivo
            cout << " + " << temp2 << "*x" << i ;
        }
        else if(i!=0 and temp2<0) {      //Si el exponente no es cero y el coeficiente es negativo
            temp2 = (-1*temp2);
            cout << " - "<< temp2 << "*x" << i;
        } 
        else if (i==0)                  //Si el exponente es cero
            cout << temp2;
        i++;                            //Incrementa el índice del exponente
    }
            
    return 0;
}


void burbuja(int *vec, int n) {

    for (int i=0; i<n-1; i++) {
        for (int j = i + 1; j < n ; j++) {
            if (vec[i] < vec[j]) {
                int temp1 = vec[i];
                vec[i] = vec[j];
                vec[j] = temp1;
            }
        }
    }
}
