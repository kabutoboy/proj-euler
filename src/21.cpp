#include <algorithm>
#include <cmath>
#include <forward_list>
#include <iostream>
#include <set>
#include <valarray>
#include <vector>

using namespace std;

void primesUnder(int n, forward_list<int> &P) {
    P = {3};
    auto it = P.begin();
    int sqrtn = sqrt(n);
    for (int candidate = 5; candidate <= n; candidate += 2) {
        // primability test
        int sqrtc = sqrt(candidate);
        bool isPrime = true;
        for (auto p: P) {
            if (p > sqrtc) {
                break;
            }
            if (candidate % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            it = P.insert_after(it, candidate);
        }
    }
    P.push_front(2);
}

void factorize(int n, forward_list<int> *primes, multiset<int> &factors) {
    factors = {};
    for (auto p: *primes) {
        while (n % p == 0) {
            factors.insert(p);
            n /= p;
        }
        if (n == 1) {
            break;
        }
    }
}

void allDivisorsExceptItself(int n, forward_list<int> *primes, set<int> &divisors) {
    multiset<int> factors;
    factorize(n, primes, factors);
    divisors = {};
    int uniqueCount = 0;
    int g = 0;
    for (auto f: factors) {
        if (f == g) continue;
        uniqueCount++;
        g = f;
    }
    valarray<int> maxPowers(uniqueCount);
    valarray<int> uniqueFactors(uniqueCount);
    valarray<int> powers(0, uniqueCount);
    valarray<int> poweredFactors(uniqueCount);
    int i = 0;
    g = 0;
    for (auto f: factors) {
        if (f == g) continue;
        maxPowers[i] = factors.count(f);
        uniqueFactors[i] = f;
        i++;
        g = f;
    }
    int nperm = 1;
    for (auto mp: maxPowers) {
        nperm *= (mp + 1);
    }
    int count = 0;
    bool done = false;
    do {
        int divisor = 1;
        poweredFactors = pow(uniqueFactors, powers);
        for (auto pf: poweredFactors) {
            divisor *= pf;
        }
        divisors.insert(divisor);
        count++;
        if (count >= nperm-1) {
            done = true;
            break;
        }
        powers[0]++;
        int i = 0;
        while (powers[i] > maxPowers[i]) {
            powers[i] = 0;
            if (i+1 < maxPowers.size()) {
                powers[i+1]++;
            } else {
                done = true;
                break;
            }
            i++;
        }
    } while (!done);
}

int sumOfDivisors(int n, forward_list<int> *P) {
    int sum = 0;
    set<int> D;
    allDivisorsExceptItself(n, P, D);
    for (auto d: D) {
        sum += d;
    }
    return sum;
}

int main () {
    cout << "List all amicable numbers under n" << endl;
    cout << "Enter n: ";
    int n;
    cin >> n;
    /* cout << "Primes under 1000 are: " << endl; */
    /* forward_list<int> P; */
    /* primesUnder(1000, P); */
    /* for (auto p: P) { */
    /*     cout << p << " "; */
    /* } */
    /* cout << "Factors of 88 are: " << endl; */
    /* multiset<int> F; */
    /* factorize(88, &P, F); */
    /* for (auto f: F) { */
    /*     cout << f << " "; */
    /* } */
    /* cout << endl; */
    /* cout << "Divisors of 88 are: " << endl; */
    /* set<int> D; */
    /* permuteFactors(&F, D); */
    /* for (auto d: D) { */
    /*     cout << d << " "; */
    /* } */
    /* cout << endl; */
    forward_list<int> primes;
    primesUnder(n, primes);
    int sum = 0;
    set<int> A;
    for (int i = 1; i < n; i++) {
        if (A.find(i) != A.end()) continue;
        int s = sumOfDivisors(i, &primes);
        /* cout << s << " "; */
        if (i == s) continue;
        int ss = sumOfDivisors(s, &primes);
        if (ss == i) {
            A.insert(i);
            A.insert(s);
            sum += i + s;
        }
    }
    for (auto a: A) {
        cout << a << " is an amicable number" << endl;
    }
    cout << "The sum of all amicable numbers listed above is " <<  sum << endl;
    return 0;
}
