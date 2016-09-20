#include <iostream>
#include <list>

using namespace std;

int main () {
    int mul;
    cin >> mul;
    list<int> num = {1};
    while (mul > 0) {
        int carry = 0;
        for (auto it = num.begin(); it != num.end(); it++) {
            int &n = *it;
            int product = n * mul;
            n = carry + product % 10;
            carry = n / 10 + product / 10;
            n %= 10;
        }
        while (carry > 0) {
            num.push_back(carry % 10);
            carry /= 10;
        }
        mul--;
    }
    num.reverse();
    int sum = 0;
    for (auto n: num) {
        sum += n;
        cout << n;
    }
    cout << endl << sum << endl;
    return 0;
}
