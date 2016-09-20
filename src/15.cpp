#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;
    int sum = 0;
    while (n > 0) {
        int i = 2*n;
        sum += i;
        n--;
    }
    cout << sum << endl;
}
