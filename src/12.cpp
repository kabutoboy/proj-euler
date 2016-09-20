#include <iostream>
#include <iomanip>
#include <queue>
#include <array>

using namespace std;

typedef long long unsigned llu;

int main () {
    int n;
    cin >> n;
    llu triangularNumber;
    int count = 0;
    queue< array<llu, 3> > q;
    for (int i = 1; count < n; i++) {
        triangularNumber = i * (i+1) / 2;
        count = 2;
        for (llu j = 2; j <= triangularNumber/2; j++) {
            if (triangularNumber % j == 0) {
                count++;
                if (count >= n) {
                    //break;
                }
            }
        }
        array<llu, 3> a;
        a[0] = i;
        a[1] = triangularNumber;
        a[2] = count;
        q.push(a);
    }
    cout << setw(10) << "ith" << setw(20) << "triangularNumber" << setw(20) << "n of divisors" << endl;
    while (!q.empty()) {
        array<llu, 3> a = q.front();
        cout << setw(10) << a[0] << setw(20) << a[1] << setw(20) << a[2] << endl;
        q.pop();
    }
    return 0;
}
