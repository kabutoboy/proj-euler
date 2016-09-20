#include <iostream>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

typedef unsigned uint;
typedef long long unsigned llu;

int main () {
    //llu _primes[] = {2llu, 3llu, 5llu, 7llu, 11llu, 13llu};
    llu _primes[] = {2llu, 3llu};
    uint count = sizeof(_primes)/sizeof(_primes[0]);
    llu x = _primes[count-1];
    llu sqrtx, sum = 2llu + 3llu;
    set<llu> primes(_primes, _primes+count);
    //cout << "Find 1st up to nth prime" << endl;
    llu n;
    cin >> n;
    while (x+2 < n) {
        x += 2llu;
        sqrtx = sqrt(x);
        bool xIsPrime = true;
        for (auto p : primes) {
            if (p > sqrtx) {
                break;
            }
            if (x % p == 0) {
                xIsPrime = false;
                break;
            }
        }
        if (xIsPrime) {
            primes.insert(x);
            sum += x;
            count++;
        }
    }
    cout << sum << endl;
}
