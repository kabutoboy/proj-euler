#include <iostream>

using namespace std;

typedef long long unsigned llu;

int main () {
    cout << "This program calculates the difference between the sum of squares and the square of sum of the number 1...n" << endl;
    cout << "Enter n: ";
    llu n;
    cin >> n;
    llu d = (((3llu*n+2llu)*n-3llu)*n-2llu)*n/12llu;
    cout << d << endl;
}
