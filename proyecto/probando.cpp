#include "biginteger.h"
#include <string>

int main(){ 
    vector<int> num1 = {1, 2};
    BigInteger a("100");
    BigInteger b("3");
    BigInteger c("100");
    a.remainder(b);
    cout << a.toString() << endl;
    return 0;
}