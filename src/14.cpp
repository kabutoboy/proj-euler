#include <iostream>

using namespace std;

typedef long long unsigned llu;

llu countCollatz(llu n) {
    llu count = 1;
    cout << n;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3*n + 1;
        }
        cout << "->" << n;
        count++;
    }
    cout << endl;
    return count;
}

int main () {
    while (true) {
        llu n;
        cin >> n;
        countCollatz(n);
    }
}

int main0 () {
    llu longestCount = 0, longestN = 0;
    for (llu i = 1; i < 1000000; i++) {
        llu count = countCollatz(i);
        if (longestCount < count) {
            longestCount = count;
            longestN = i;
        }
    }
    cout << longestN << " produces " << longestCount << endl;
    return 0;
}
