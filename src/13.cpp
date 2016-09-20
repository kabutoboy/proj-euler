#include <iostream>
#include <array>
#include <cmath>

using namespace std;

typedef long long unsigned llu;

int main () {
    array<int, 5000> a;
    for (int i = 0; i < 100; i++) {
        string ln;
        getline(cin, ln);
        for (int j = 0; j < 50; j++) {
            a[i*50 + j] = ln.at(j) - '0';
        }
    }
    double sum = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = i; j < 5000; j += 50) {
            sum += (double) a[j] / pow(10, i);
        }
    }
    sum *= pow(10, 9-(int)log10(sum));
    cout << (llu)sum << endl;
}
