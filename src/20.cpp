#include <iostream>
#include <vector>

using namespace std;

typedef long long unsigned llu;

int main () {
    int m;
    cin >> m;
    vector<int> num{1};
    for (int mul{1}; mul <= m; mul++) {
        int add = 0;
        for (int i = 0; i < num.size(); i++) {
            int tmp = num[i] * mul;
            num[i] = add + tmp % 10;
            add = num[i] / 10 + tmp / 10;
            num[i] %= 10;
        }
        while (add > 0) {
            num.push_back(add % 10);
            add /= 10;
        }
        for (int i = num.size()-1; i >= 0; i--) {
            cout << num[i];
        }
        cout << endl;
    }
    int sum = 0;
    for (auto n: num) {
        sum += n;
    }
    cout << sum << endl;
    return 0;
}
