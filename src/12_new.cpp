#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef long long unsigned llu;

set<llu> firstNPrimes(int n) {
    set<llu> P = { 3llu };
    llu candidate = 3llu;
    int count = 1;
    while (count < n-1) {
        candidate += 2;
        llu sqrtCandidate = sqrt(candidate);
        bool isPrime = true;
        for (auto p : P) {
            if (p > sqrtCandidate) {
                break;
            }
            if (candidate % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            P.insert(candidate);
            count++;
        }
    }
    P.insert(2llu);
    return P;
}

multiset<llu> factorize(llu n, set<llu> primes) {
    multiset<llu> factors;
    llu sqrtn = sqrt(n);
    for (auto p : primes) {
        if (n == 1) {
            break;
        }
        while (n % p == 0) {
            factors.insert(p);
            n /= p;
        }
    }
    return factors;
}

int countDivisors(llu n, set<llu> primes) {
    multiset<llu> factors = factorize(n, primes);
    int divisors = 1;
    llu lastp = 0;
    for (auto p : factors) {
        if (lastp != p) {
            int count = factors.count(p);
            divisors *= count + 1;
            lastp = p;
        }
    }
    return divisors;
}

int main () {
    int n;
    cin >> n;
    set<llu> primes = firstNPrimes(n);
    llu triangleNumber;
    int count = 0;
    queue< array<llu, 3> > q;
    for (llu i = 1; count < n; i++) {
        triangleNumber = i * (i+1llu) / 2llu;
        count = countDivisors(triangleNumber, primes);
        array<llu, 3> a;
        a[0] = i;
        a[1] = triangleNumber;
        a[2] = count;
        q.push(a);
    }
    cout << setw(10) << "ith" << setw(20) << "triangleNumber" << setw(20) << "n of divisors" << endl;
    while (!q.empty()) {
        array<llu, 3> a = q.front();
        cout << setw(10) << a[0] << setw(20) << a[1] << setw(20) << a[2] << endl;
        q.pop();
    }
    return 0;
}
