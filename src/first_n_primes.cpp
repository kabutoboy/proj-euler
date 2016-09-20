#include <cmath>
#include <forward_list>
#include <iomanip>
#include <iostream>

using namespace std;

typedef unsigned uint;
typedef long long unsigned llu;

int main () {
    llu n;
    cin >> n;
    forward_list<llu> primes;
    auto it = primes.insert_after(primes.before_begin(), 3llu);
    llu candidate = 5llu;
    llu count = 2llu;
    while (count < n) {
        bool isPrime = true;
        for (auto p : primes) {
            llu sqrtc = sqrt(candidate);
            if (p > sqrtc) break;
            if (candidate % p == 0llu) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            it = primes.insert_after(it, candidate);
            count++;
        }
        candidate += 2llu;
    }
    primes.push_front(2llu);
    llu i = 1llu;
    cout << setw(24) << "i" << setw(24) << "ith prime" << setw(24) << "n of primes < i" << endl;
    for (auto p : primes) {
        cout << setw(24) << i << setw(24) << p;
        llu j = 0;
        for (auto q : primes) {
            if (q > i) break;
            j++;
        }
        cout << setw(24) << j << endl;
        i++;
    }
    return 0;
}
