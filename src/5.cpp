#include <iostream>
#include <set>
#include <cmath>

using namespace std;

/*
1
2
3
4 2 2
5
6 3 2
7
8 2 2 2
9 3 3
10 5 2

1 2 3 2 5 7 2 3
*/

typedef long long unsigned llu;

multiset<int> factorize(int n) {
    multiset<int> factors;
    if (n == 1) {
        factors.insert(1);
        return factors;
    } else if (n < 1) {
        factors.insert(0);
        return factors;
    }
    while (n % 2 == 0) {
        factors.insert(2);
        n /= 2;
    }
    int sqrtn = sqrt(n);
    for (int p = 3; p <= sqrtn; p += 2) {
        int isPrime = true;
        int sqrtp = sqrt(p);
        for (int i = 3; i <= sqrtp; i += 2) {
            if (p % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            while (n % p == 0) {
                factors.insert(p);
                n /= p;
            }
        }
    }
    if (n != 1) {
        factors.insert(n);
    }
    return factors;
}

multiset<int> smallestNumberDivisibleBy1UpTo(int n) {
    multiset<int> factors;
    for (int i = 2; i <= n; i++) {
        multiset<int> ifactors = factorize(i);
        int lastf = -1;
        for (int f : ifactors) {
            if (lastf != -1 && f == lastf) {
                continue;
            }
            int needMore = ifactors.count(f) - factors.count(f);
            for (int j = 0; j < needMore; j++) {
                factors.insert(f);
            }
            lastf = f;
        }
    }
    return factors;
}

int main () {
    while (true) {
        cout << "This program finds the smallest number that can be divided by each of the numbers from 1...n without any remainder." << endl;
        cout << "Enter n: ";
        int n;
        cin >> n;
        multiset<int> factors = smallestNumberDivisibleBy1UpTo(n);
        llu m = 1;
        cout << "1";
        for (int i : factors) {
            cout << "*" << i;
            m *= i;
        }
        cout << " = " << m << endl;
    }
}
