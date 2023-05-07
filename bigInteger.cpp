/*
Proyecto Final Estructura de Datos - BIg Integer
Profesor: Carlos Ramirez
Estudiante: David Nino Galvis
Fecha: 2 de Mayo del 2023

*/


#include "bigInteger.h"


void bigInteger::stringToBigInt(string &cad){
    for(int i = 0; i < cad.size(); i++){
        char c = cad[i];
        int digito = c - '0';
        vec.insert(vec.begin(), digito);
    }
}

string bigInteger::toString() {
    string ans = "";
    for (int i = vec.size() - 1; i >= 0; i--) {
        // Recorro el ciclo de atras para adelante y se convierte cada dígito a un carácter y se concatena a la cadena de salida.
        char digit = vec[i] + '0';
        ans += digit;
    }
    // esta tuve problemas pero creo que se soluciono
    return ans;
}