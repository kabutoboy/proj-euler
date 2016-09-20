#include <iostream>

using namespace std;

/* Straight forward way
int main () {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
*/

// Clever way
int sum_of_multiple(int x, int m) {
    int n = m / x;
    return x * n * (n+1) / 2;
}

int main () {
    int sum = 0;
    sum = sum_of_multiple(3, 999) + sum_of_multiple(5, 999) - sum_of_multiple(15, 999);
    cout << sum << endl;
    return 0;
}
