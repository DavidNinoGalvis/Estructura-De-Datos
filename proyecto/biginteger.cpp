/*
Materia: Estructura De Datos
Implementación Big Integer
Profesor: Carlos Ramirez - Luis Noreña
Autor: David Nino Galvis
Date: 28 May 2023
*/
#include "biginteger.h"

/*
- Constructor:
Entrada: String del numero a convertir.
Convierte el string ingresado a un vector para poder ser manipulado
*/

/*
Constructor por Defecto:
Entrada: Vacia

*/
BigInteger::BigInteger(){
}

BigInteger::BigInteger(const string& str) {
    int len = str.length();
    int start = 0;
    if (str[0] == '-') {
        start = 1;
        signo = 1;
    } else {
        signo = 0;
     }

    for (int i = len - 1; i >= start; --i) {
        digito.push_back(str[i] - '0');
    }
}

BigInteger::BigInteger(const BigInteger& num){
    signo = num.signo;
    digito = num.digito;
}

/*
Funcion Auxiliar:
Esta función retorna el signo del bigInteger, muy importante para facilitar otras implementaciones
*/
bool BigInteger::defsigno(){
    return signo;
}

/*
Funcion Auxiliar:
Esta función nos sirve para saber el tamaño del numero, retornaria la cantidad de digitos del BigInteger
*/
int BigInteger::size(){
    return digito.size();
}

/*
Salida: Cadena String
Con esta función podemos retornar un objeto BigInteger convertido en una cadena de texto String
*/
string BigInteger::toString(){
    string ans = "";
    if (signo) {
        ans = "-" + ans;
    }
    for(int i = size() - 1; i >= 0 ; --i){
        ans += digito[i] + 48; 
    }
    return ans;
}

/*
Funcion Auxiliar:
Retorna el valor del vector en la posición deseada
*/
int BigInteger::getDigit(int pos) {
    return digito[pos];
}

/* //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void sumaAux(vector<int>& num1, BigInteger& num2){
    /*ENTRADA:
    Para utilizar esta implementación se necesita un vector y un elemento BigInteger*/
    /*Realizamos la sumaAux de la manera convencional, alineando el vector con un biginteger teniendo en cuenta cual de los 2 numeros
    tiene una mayor longitud, para asignar valores*/
    int maxSize;
    int num1Size = num1.size();
    int num2Size = num2.size();
    if (num1Size > num2Size) {
        maxSize = num1Size;
    } else {
        maxSize = num2Size;
    }
    // Realizar la sumaAux de los números
    int carry = 0;
    int sumaAux, i;
    num1.resize(maxSize + 1);
    for(i = 0; i < maxSize ; ++i){
        sumaAux = carry;
        if(i < num1Size) 
            sumaAux += num1[i];
        if(i < num2Size) 
            sumaAux += num2.getDigit(i);
        num1[i] = sumaAux % 10;
        carry = sumaAux / 10;
    }
    if(carry)
        num1[i] = carry;
    else
        num1.resize(maxSize);
}

/*
Función restaAux
Entrada: Una referencia a un vector de enteros num1 y un objeto BigInteger num2.
Salida: Ninguna (void).
Descripción: Realiza la resta entre el vector de enteros num1 y el objeto BigInteger num2. Esta función es utilizada como auxiliar en la resta de objetos BigInteger.
*/
void restaAux(vector<int>& num1, BigInteger& num2) {
    bool carryFlag = true;
    bool subtractFlag = false;
    bool zeroFlag = true;
    bool resizeFlag = true;
    int currentIndex = 0;
    int firstNonZeroIndex = 0;

    while (currentIndex < num1.size() && resizeFlag) {
        if (currentIndex < num2.size()) {
            if (num1[currentIndex] < num2.getDigit(currentIndex)) {
                num1[currentIndex] += 10;
                subtractFlag = true;
            }
            num1[currentIndex] -= num2.getDigit(currentIndex);
        }
        else if (!subtractFlag) {
            carryFlag = false;
        }

        if (subtractFlag) {
            if (num1[currentIndex + 1] != 0) {
                num1[currentIndex + 1] -= 1;
            }
            else {
                num1[currentIndex + 1] = 9;
            }
            subtractFlag = false;
        }

        if (num1[currentIndex] == 0) {
            if (zeroFlag && currentIndex != 0) {
                firstNonZeroIndex = currentIndex;
                zeroFlag = false;
            }
        }
        else {
            zeroFlag = true;
        }

        ++currentIndex;

        if (!carryFlag && (currentIndex == num1.size())) {
            resizeFlag = false;
        }
    }

    if (!zeroFlag && (currentIndex == num1.size())) {
        num1.resize(firstNonZeroIndex);
    }
}

/*
Función divisionTwo
Entrada: Dos objetos BigInteger, num1 y num2.
Salida: Un vector de enteros.
Descripción: Realiza la división entre num1 y num2 y retorna el cociente como un vector de enteros.
*/
vector<int> divisionTwo(BigInteger& num1, BigInteger& num2){
    vector<int> ration = {0};
    BigInteger one("1");
    BigInteger value(num2.toString());
    while(num2 < num1){
        num2.add(value);
        sumaAux(ration, one);
    }
    if(num2 == num1){
        sumaAux(ration, one);
        num1 = BigInteger("0");
    } else{
        num2.substract(value);
        num1.substract(num2);
    }
    return ration;
}

/*
Función multiplicacionAux
Entrada: Dos vectores de enteros por referencia, num1 y num2.
Salida: Ninguna (void).
Descripción: Esta función realiza la multiplicación de dos vectores que representan números enteros grandes. El resultado se almacena en el vector num1.

El algoritmo utiliza el método de la multiplicación de columnas para realizar la multiplicación. Itera sobre cada dígito de num1 y num2, realiza la
 multiplicación correspondiente y actualiza los dígitos del vector ans. Luego, se ajustan los dígitos y se eliminan los ceros no significativos del resultado.

Es importante destacar que los vectores num1 y num2 se pasan por referencia, lo que significa que se modifican directamente dentro de la función.
*/

void multiplicacionAux(vector<int>& num1, BigInteger num2, BigInteger value) {
    BigInteger cont("1");
    BigInteger one("1");

    while(cont < num2){
        sumaAux(num1, value);
        cont.add(one);
    }
}


 /*
Función add
Entrada: Un objeto BigInteger num2.
Salida: Ninguna (void).
Descripción: Realiza la suma entre el objeto BigInteger actual y num2 y actualiza el valor del objeto actual con el resultado.
*/
void BigInteger::add(BigInteger& num2){
    bool isSameSign = (defsigno() == num2.defsigno());
    bool isNum2LessThanOrEqual = (num2 <= digito);
    bool hasZeroLastDigit = false;

    if(isSameSign) {
        sumaAux(digito, num2);
    } else {
        if(isNum2LessThanOrEqual) {
            restaAux(digito, num2);
            hasZeroLastDigit = (!digito[size() - 1]);
            if(hasZeroLastDigit) 
                signo = false;
        } else {
            BigInteger temp1(*this);
            vector<int> temp2(num2.size());
            for(int i = 0; i < num2.size(); ++i)
                temp2[i] = num2.getDigit(i);
            restaAux(temp2, temp1);
            signo = num2.defsigno();
            digito = temp2;
        }
    }
}

/*
Función substract
Entrada: Un objeto BigInteger num2.
Salida: Ninguna (void).
Descripción: Realiza la resta entre el objeto BigInteger actual y num2 y actualiza el valor del objeto actual con el resultado.
*/
void BigInteger::substract(BigInteger& num2){
    bool isDifferentSign = (defsigno() != num2.defsigno());
    bool isNum2LessThanOrEqual = (num2 <= digito);
    bool hasZeroLastDigit = false;

    if (isDifferentSign) {
        sumaAux(digito, num2);
    } else {
        if (isNum2LessThanOrEqual) {
            restaAux(digito, num2);
            hasZeroLastDigit = (!digito[size() - 1]);
            if (hasZeroLastDigit) 
                signo = false;
        } else {
            BigInteger temp1(*this);
            vector<int> temp2(num2.size());
            for (int i = 0; i < num2.size(); ++i)
                temp2[i] = num2.getDigit(i);
            restaAux(temp2, temp1);
            signo = !num2.defsigno();
            digito = temp2;
        }
    }
}

/*
Función product
Entrada: Un objeto BigInteger num2.
Salida: Ninguna (void).
Descripción: Realiza la multiplicación entre el objeto BigInteger actual y num2 y actualiza el valor del objeto actual con el resultado.
*/
void BigInteger::product(BigInteger& num2){
    BigInteger zero("0");
    BigInteger alter(*this);

    signo = !(num2.defsigno() == signo);

    if(*(this) == zero || num2 == zero){
        digito = {0};
    } else if(num2 <= *(this)){
        multiplicacionAux(digito, num2, *(this));
    } else{
        digito = num2.digito;
        multiplicacionAux(digito, alter, num2);
    }
}

/*
Función quotient
Entrada: Un objeto BigInteger num2.
Salida: Ninguna (void).
Descripción: Realiza la división entre el objeto BigInteger actual y num2 y actualiza el valor del objeto actual con el cociente.
*/
void BigInteger::quotient(BigInteger& num2){
    vector<int> ration = {0};

    signo = !(num2.defsigno() == signo);

    if(*(this) < num2){
        digito = {1};
    } else{
        ration = divisionTwo(*(this), num2);
        digito = ration;
    }
}

/*
Función remainder
Entrada: Un objeto BigInteger.
Salida: Ninguna.
Descripción: Calcula el residuo de la división entre el objeto actual y el BigInteger pasado como parámetro.
*/
void BigInteger::remainder(BigInteger& num2){
    divisionTwo(*(this), num2);
}


/*
Función pow
Entrada: Un número entero.
Salida: Ninguna.
Descripción: Calcula la potencia del objeto actual elevado al número entero pasado como parámetro.
*/
void BigInteger::pow(int num2) {
    BigInteger base(*this);
    BigInteger result("1");
    bool flag = true;

    // Caso especial: si el exponente es cero, el resultado es 1.
    if (num2 == 0) {
        digito = {1};
        flag = false;
    }

    // Realizar multiplicaciones repetidas según el exponente.
    while (num2 > 0 && flag) {
        if (num2 % 2 == 1) {
            result.product(base);
        }
        base.product(base);
        num2 /= 2;
    }

    digito = result.digito;
    signo = result.signo;
}

/* OPERADORES ARITMETRICOS*/

/*
Operador de suma
Entrada: Un objeto BigInteger.
Salida: Un objeto BigInteger que es la suma del objeto actual y el BigInteger pasado como parámetro.
Descripción: Realiza la operación de suma entre el objeto actual y el BigInteger pasado como parámetro.
*/
BigInteger BigInteger::operator+(BigInteger& num2){
    BigInteger ans(*this);
    ans.add(num2);
    return ans;
}
/*
Operador de resta
Entrada: Un objeto BigInteger.
Salida: Un objeto BigInteger que es la resta del objeto actual y el BigInteger pasado como parámetro.
Descripción: Realiza la operación de resta entre el objeto actual y el BigInteger pasado como parámetro.
*/
BigInteger BigInteger::operator-(BigInteger& num2){
    BigInteger ans(*this);
    ans.substract(num2);
    return ans;
}


/*
Operador de multiplicación
Entrada: Un objeto BigInteger.
Salida: Un objeto BigInteger que es el producto del objeto actual y el BigInteger pasado como parámetro.
Descripción: Realiza la operación de multiplicación entre el objeto actual y el BigInteger pasado como parámetro.
*/
BigInteger BigInteger::operator*(BigInteger& num2){
    BigInteger ans(*this);
    ans.product(num2);
    return ans;
}


/*
Operador de división
Entrada: Un objeto BigInteger.
Salida: Un objeto BigInteger que es el cociente de la división entre el objeto actual y el BigInteger pasado como parámetro.
Descripción: Realiza la operación de división entre el objeto actual y el BigInteger pasado como parámetro.
*/
BigInteger BigInteger::operator/(BigInteger& num2){
    BigInteger ans(*this);
    ans.quotient(num2);
    return ans;
}


/*
Operador de módulo
Entrada: Un objeto BigInteger.
Salida: Un objeto BigInteger que es el residuo de la división entre el objeto actual y el BigInteger pasado como parámetro.
Descripción: Realiza la operación de módulo entre el objeto actual y el BigInteger pasado como parámetro.
*/
BigInteger BigInteger::operator%(BigInteger& num2){
    BigInteger ans(*this);
    ans.remainder(num2);
    return ans;
}


/*
Operador de menor o igual que
Entrada: Un objeto BigInteger y un vector de enteros.
Salida: Un valor booleano.
Descripción: Compara si el objeto actual es menor o igual que el vector de enteros pasado como parametro
*/
bool operator<=(BigInteger& num1, vector<int>& num2){
    int i = num1.size() - 1, flag = 1;
    bool ans;
    if(num1.size() != num2.size()){
        ans = num1.size() < num2.size();
    }else{
        while(i >= 0 && flag){
            if(num1.getDigit(i) != num2[i]){
                ans = num1.getDigit(i) < num2[i];
                flag = 0;
            }
            --i;
        }
        if(flag) ans = true;
    }
    return ans;
}

/*
Operador de igualdad
Entrada: Un objeto BigInteger.
Salida: Un valor booleano.
Descripción: Compara si el objeto actual es igual al BigInteger pasado como parámetro.
*/
bool BigInteger::operator==(BigInteger& num2) {
    bool isEqual = true;
    int index = size() - 1;

    if (signo != num2.defsigno() || size() != num2.size()) {
        isEqual = false;
    } else {
        while (index >= 0 && isEqual) {
            if (digito[index] != num2.getDigit(index)) {
                isEqual = false;
            }
            --index;
        }
    }
    return isEqual;
}

/*
Operador de menor que
Entrada: Un objeto BigInteger.
Salida: Un valor booleano.
Descripción: Compara si el objeto actual es menor que el BigInteger pasado como parámetro.
*/
bool BigInteger::operator<(BigInteger& num2) {
    bool isLess = false;
    int index;
    int flag = 1;

    if(size() < num2.size()){
        isLess = true;
    } else if(size() == num2.size()){
        index = 0;
        while(index < size() && flag) {
            if (digito[index] != num2.getDigit(index)) {
                isLess = (!signo ? digito[index] < num2.getDigit(index) : digito[index] > num2.getDigit(index));
                flag = 0;
            }
            index++;
        }
    }

    return isLess;
}


/*
Operador de menor o igual que
Entrada: Un objeto BigInteger.
Salida: Un valor booleano.
Descripción: Compara si el objeto actual es menor o igual que el BigInteger pasado como parámetro.
*/
bool BigInteger::operator<=(BigInteger& num2) {
    bool ans = false;
    int i = size() - 1;
    int flag = 1;

    if (signo != num2.signo) {
        if (num2.defsigno()) {
            ans = true;
        } else {
            ans = false;
        }
    } else if (size() != num2.size()) {
        if (signo) {
            ans = size() > num2.size();
        } else {
            ans = size() < num2.size();
        }
    } else {
        while (i >= 0 && flag) {
            if (digito[i] != num2.getDigit(i)) {
                if (signo) {
                    ans = digito[i] > num2.getDigit(i);
                } else {
                    ans = digito[i] < num2.getDigit(i);
                }
                flag = 0;
            }
            --i;
        }
        if (flag) {
            ans = true;
        }
    }
    return ans;
}

/*||||||||||||||||||||| OPERACIONES ESTATICAS ||||||||||||||||||||||||*/
/*
Función sumarListaValores
Entrada: Una lista de objetos BigInteger.
Salida: Un objeto BigInteger.
Descripción: Calcula la suma de todos los objetos BigInteger en la lista y retorna el resultado.
*/
BigInteger BigInteger::sumarListaValores(list<BigInteger>& l ){
    list<BigInteger>::iterator it = l.begin();
    BigInteger ans = *it;
    ++it;
    while (it != l.end()) {
        ans.add(*it);
        ++it;
    }
    return ans;
}

/*
Función multiplicarListaValores
Entrada: Una lista de objetos BigInteger.
Salida: Un objeto BigInteger.
Descripción: Calcula el producto de todos los objetos BigInteger en la lista y retorna el resultado.
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger>& l){
    list<BigInteger>::iterator it = l.begin();
    BigInteger ans = *it;
    ++it;

    while (it != l.end()) {
        ans.product(*it);
        ++it;
    }
    return ans;
}