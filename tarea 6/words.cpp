#include <iostream>
#include <array>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

void printArray(array<string, 26> array){
    int i = 0;
    for (i = 0 ; i < array.size() ; i++)
        cout << array[i] << endl;
}

int main(){
    
    array<string, 26> lenguajes;
    bool flag = true;
    string palabra;
    int indice = 0;
    while(flag == true){
        cin >> palabra;
        if (palabra == "#")
            flag = false;
        else if (indice < 26){
            lenguajes[indice] = palabra;
            ++indice;
        }
    }

    bool flag2 = true;
    map<char, int> mapa;
    char clave;
    while(flag2 == true){
        scanf("%c",&clave);
        if (clave == '#')
            flag2 = false;
        else if (mapa.find(clave) == mapa.end()){
            cout << "No existe. Se agrega por primera vez" << endl;
            mapa[clave] = 1;
        }
        else{
            // En caso de que ya exista
            cout << "Ya existe. Se aumenta su conteo" << endl;
            mapa[clave]++;
        }
    }
    
    map<string, int>::iterator iterador;
    for (iterador = mapa.begin(); iterador != mapa.end(); iterador++)
    {
        string lenguaje = iterador->first;
        int conteo = iterador->second;
        cout << "Clave " << lenguaje << " Valor " << conteo << endl;
    }


    return 0;

}