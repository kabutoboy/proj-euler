#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long unsigned llu;

int main () {
    string bignum;
    getline(cin, bignum);
    int len = bignum.length();
    //cout << "Find n adjacent digits that have the greatest product" << endl;
    //cout << "Enter n: ";
    int n;
    string tmp;
    getline(cin, tmp);
    n = stoi(tmp);
    cout << "bignum is " << bignum << endl;
    cout << "len is " << len << endl;
    cout << "n is " << n << endl;
    //vector<int> q;
    llu p = 1, q = 1;
    for (int i = 0; i < len-n; i++) {
        q = 1;
        for (int j = i; j < i+n; j++) {
            int k = bignum.at(j) - '0';
            q *= k;
        }
        if (p < q) {
            p = q;
        }
    }
    cout << p << endl;
    return 0;
}
