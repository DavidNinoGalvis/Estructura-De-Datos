#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    int sign;

public:
    BigInteger(const string& str) {
        int len = str.length();
        int start = (str[0] == '-') ? 1 : 0;
        sign = (start == 1) ? 1 : 0;

        for (int i = len - 1; i >= start; --i) {
            digits.push_back(str[i] - '0');
        }
    }

    bool operator<(const BigInteger& other) const {
        if (sign != other.sign) {
            return sign > other.sign;
        }

        int size1 = digits.size();
        int size2 = other.digits.size();

        if (size1 != size2) {
            return (size1 < size2) ^ sign;
        }

        for (int i = size1 - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return (digits[i] < other.digits[i]) ^ sign;
            }
        }

        return false;
    }
};

int main() {
    int contador = 1;
    string num1, num2;

    while (cin >> num1) {
        cout << "Case " << contador++ << ": ";

        cin >> num2;

        BigInteger big1(num1);
        BigInteger big2(num2);
        
        if (big1 < big2) {
            cout << "Smaller" << endl;
        } else if (big2 < big1) {
            cout << "Bigger" << endl;
        } else {
            cout << "Same" << endl;
        }
    }

    return 0;
}
