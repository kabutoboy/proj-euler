#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int ull;

bool isPrime(ull x) {
    if (x % 2 == 0) return false;
    ull sqrtx = sqrt(x);
    for (ull i = 3; i <= sqrtx; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    cout << "Find largest prime factor of ";
    ull x;
    cin >> x;
    ull i = 2;
    ull p;
    while (x > 1) {
        if (isPrime(i)) {
            if (x % i == 0) {
                x /= i;
                p = i;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    cout << p << endl;
    return 0;
}
