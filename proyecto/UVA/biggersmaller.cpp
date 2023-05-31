#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BigInteger {
private:
    vector<int> digitos;
    int signo;

public:
    BigInteger(const string& str) {
        int len = str.length();
        int start = 0;
        if (str[0] == '-') {
            start = 1;
            signo = 1;
        } else {
            signo = 0;
        }

        for (int i = len - 1; i >= start; --i) {
            digitos.push_back(str[i] - '0');
        }
    }


bool operator<(const BigInteger& other) {
    bool isLess = false;

    if (signo != other.signo) {
        isLess = signo > other.signo;
    } else {
        int size1 = digitos.size();
        int size2 = other.digitos.size();

        if (size1 < size2) {
            isLess = true;
        } else if (size1 == size2) {
            int index = size1 - 1;
            int flag = 1;

            while (index >= 0 && flag) {
                if (digitos[index] != other.digitos[index]) {
                    isLess = (!signo ? digitos[index] < other.digitos[index] : digitos[index] > other.digitos[index]);
                    flag = 0;
                }
                --index;
            }
        }
    }
    return isLess;
}

int main() {
    /*Para la realizacion de este Uva, consiste en dividir la entrada de 2 numeros en 4, que seria la parte entera y la parte decimal
    para asi pasar a comparar la parte entera del num1 y la parte entera del num2 y en caso que de sean iguales, se pasa a comparar la parte
    decimal de los numeros, para esto utilice una función que dividie una cadena en subcadenas y me ahorro lineas de codigo para no hacerlo desde 0*/
    int contador = 1;
    string num1, num2;
    string num1FirstPart, num2FirstPart;
    string num1SecondPart, num2SecondPart;
    while (cin >> num1) {
        cout << "Case " << contador++ << ": ";
        num1FirstPart = "";
        num2FirstPart = "";
        cin >> num2;
        // Obtenemos la parte entera de los números
        /* UTILIZAMOS ESTA FUNCION PARA EXTRAER UNA SUB CADENA DE LA PRINCIPAL Y ASI DIVIDIR LA PARTE ENTERA DE LA PARTE
        DECIMAL*/
        int dotIndex = num1.find('.');
        num1FirstPart = num1.substr(0, dotIndex);
        
        dotIndex = num2.find('.');
        num2FirstPart = num2.substr(0, dotIndex);
        
        BigInteger big1Int(num1FirstPart);
        BigInteger big2Int(num2FirstPart);
        
        // Realizamos la primera comparación de las partes enteras
        if (big1Int < big2Int) {
            cout << "Smaller" << endl;
        } else if (big2Int < big1Int) {
            cout << "Bigger" << endl;
        } else {
            num1SecondPart = num1.substr(dotIndex + 1);
            num2SecondPart = num2.substr(dotIndex + 1);
            
            BigInteger big1Decimal(num1SecondPart);
            BigInteger big2Decimal(num2SecondPart);
            
            // Realizamos la comparación de las partes decimales
            if (big1Decimal < big2Decimal) {
                cout << "Smaller" << endl;
            } else if (big2Decimal < big1Decimal) {
                cout << "Bigger" << endl;
            } else {
                cout << "Same" << endl;
            }
        }
    }
    return 0;
}
