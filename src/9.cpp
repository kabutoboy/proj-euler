#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Let (a, b, c) be a Pythagorean triple i.e. integer solution to a^2 + b^2 = c^2" << endl;
    cout << "a = m^2 - n^2, b = 2mn, c = m^2 + n^2 where m > n" << endl;
    cout << "We want a + b + c = 1000" << endl;
    cout << "So 2m^2 + 2mn = 1000" << endl;
    cout << "m^2 + mn = 500" << endl;
    cout << "m(m + n) = 500" << endl;
    bool found = false;
    int m, n;
    for (m = sqrt(500); m > 0; m--) {
        for (n = sqrt(500); n > 0; n--) {
            if (m * (m+n) == 500) {
                cout << "m = " << m << ", n = " << n << endl;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    int a = m*m - n*n, b = 2*m*n, c = m*m + n*n;
    cout << "(a, b, c) = " << "(" << a << "," << b << "," << c << ")" << endl;
    long long unsigned abc = a * b * c;
    cout << "abc = " << abc << endl;
}
