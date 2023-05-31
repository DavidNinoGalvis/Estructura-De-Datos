#include "biginteger.h"
#include <string>

int main(){ 
    vector<int> num1 = {1, 2};
    BigInteger a("100");
    BigInteger b("3");
    BigInteger c("100");
    printf("menor: %d\n", c<a);
    printf("menor igual: %d\n", c<=a);
    printf("igual: %d\n", c==a);
    b.product(a);
    cout << a.toString() << endl;
    BigInteger base("2");
    cout << "Ejemplo de Potencia " << base.toString() << endl;
    base.pow(5);
    cout << "Ejemplo de Potencia " << base.toString() << endl;
    return 0;
}