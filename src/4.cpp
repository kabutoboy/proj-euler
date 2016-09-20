#include <iostream>
#include <queue>
#include <cmath>
#include <array>

using namespace std;

int digitAt(int i, int x) {
    return x % (int)pow(10, i+1) / (int)pow(10, i);
}
int numberOfDigitsInBase10(int x) {
    int n;
    for (n = 0; x / (int)pow(10, n) > 0; n++) {}
    return n;
}

struct GreaterThanBy3rdVal {
    bool operator()(const array<int, 3>& lhs, const array<int, 3>& rhs) const {
        return lhs[2] < rhs[2];
    }
};

int main () {
    priority_queue< array<int, 3>, vector< array<int, 3> >, GreaterThanBy3rdVal > Q;
    for (int i = 999; i > 99; i--) {
//        cout << i << " has " << numberOfDigitsInBase10(i) << " digits" << endl;
        bool isPalindrome = false;
        for (int j = 999; j > 99; j--) {
            isPalindrome = true;
            int x = i * j, n = numberOfDigitsInBase10(x);
            for (int k = 0; k < n/2; k++) {
                //cout << x << "," << n << "," << digitAt(k, x) << "," << digitAt(n-k-1, x) << endl;
                if (digitAt(k, x) != digitAt(n-k-1, x)) {
                    isPalindrome = false;
                }
            }
            if (isPalindrome) {
                //cout << i << " * " << j << " = " << x << endl;
                array<int, 3> a = {i, j, x};
                Q.push(a);
                //break;
            }
        }
        if (isPalindrome) {
            //break;
        }
    }
    while (!Q.empty()) {
        array<int, 3> a = Q.top();
        cout << a[2] << " = " << a[0] << " * " << a[1] << endl;
        Q.pop();
    }
    //cout << "The largest palindrome that is a product of two 3-digit numbers is " << Q.top() << endl;
    return 0;
}
