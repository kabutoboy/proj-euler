#include <iostream>
#include <cmath>

using namespace std;

// Straightforward way
/*int main () {
    unsigned long int a = 1, b = 1, c = 0, sum = 0;
    while (c < 4000000u) {
        c = a + b;
        a = b;
        b = c;
        if (c % 2) continue;
        sum += c;
    }
    cout << sum << endl;
    return 0;
}*/

// Clever way
int main () {
    double phi_cubed = 4.236067977499789;
    unsigned long int x = 2, sum = 0;
    do {
        cout << x << endl;
        sum += x;
        x = round(x * phi_cubed);
    } while (x < 4000000u);
    cout << sum << endl;
    return 0;
}

