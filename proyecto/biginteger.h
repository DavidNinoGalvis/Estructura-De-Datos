/*
Materia: Estructura De Datos
Implementación Big Integer
Profesor: Carlos Ramirez - Luis Noreña
Autor: David Nino Galvis
Date: 28 May 2023
*/

#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class BigInteger {
private:
    vector<int> digito;
    bool signo;

public:
    /*CONSTRUCTORES*/
    BigInteger(const string& str);
    BigInteger(const BigInteger& num);
    BigInteger();

    /*Modificadoras*/
    void add(BigInteger& num2);
    void product(BigInteger& num2);
    void substract(BigInteger& num2);
    void quotient(BigInteger& num2);
    void remainder(BigInteger& num2);
    void pow(int num2);

    /*Funciones Auxiliares Analizadoras*/
    string toString();
    bool defsigno();
    int size();
    int getDigit(int pos);

    /* SOBRECARGA DE OPERADORES */
    BigInteger operator+(BigInteger& num2);
    BigInteger operator-(BigInteger& num2);
    BigInteger operator*(BigInteger& num2);
    BigInteger operator/(BigInteger& num2);
    BigInteger operator%(BigInteger& num2);
    bool operator==(BigInteger& num2);
    bool operator<(BigInteger& num2);
    bool operator<=(BigInteger& num2);

    /* OPERACIONES ESTATICAS */
    static BigInteger sumarListaValores(list<BigInteger>& l);
    static BigInteger multiplicarListaValores(list<BigInteger>& l);
};

/* Funciones auxiliares */
bool operator<=(BigInteger& num1, vector<int>& num2);
void sumaAux(vector<int>& num1, BigInteger& num2);
void restaAux(vector<int>& num1, BigInteger& num2);
void multiplicacionAux(vector<int>& num1, vector<int>& num2);
vector<int> divisionTwo(BigInteger& num1, BigInteger& num2);

#endif