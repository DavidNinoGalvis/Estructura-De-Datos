/*
Proyecto Final Estructura de Datos - BIg Integer
Profesor: Carlos Ramirez
Estudiante: David Nino Galvis
Fecha: 2 de Mayo del 2023

*/


#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include <vector>
#include <string>

using namespace std;


class bigInteger{
    private:
        vector<int> vec;

    public:

        void stringToBigInt(string &num);
        void add(bigInteger &bigInt);
        void product(bigInteger &bigInt);
        void substract(bigInteger &bigInt);
        void quotient(bigInteger &bigInt);
        void remainder(bigInteger &bigInt);
        void pow(bigInteger &bigInt);
        string toString();

        /**************
         OPERADORES
        **************/
        /*Pasamos el objeto BigInt por referencia para evitar que se realice la copia*/
        bigInteger operator+(bigInteger &bigInt);
        bigInteger operator-(bigInteger &bigInt);
        bigInteger operator*(bigInteger &bigInt);
        bigInteger operator/(bigInteger &bigInt);
        bigInteger operator%(bigInteger &bigInt);
        bigInteger operator==(bigInteger &bigInt);
        bigInteger operator<(bigInteger &bigInt);
        bigInteger operator<=(bigInteger &bigInt);

};
#endif
