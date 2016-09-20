#include <iostream>
#include <array>

using namespace std;

typedef long long unsigned llu;

int main () {
    int n;
    cin >> n;
    array<int, 400> grid;
    for (int i = 0; i < 400; i++) {
        cin >> grid[i];
    }
    array<llu, 4> products;
    products.fill(0);
    for (int i = 0; i < 400; i++) {
        long long unsigned x = 1, y = 1, ne = 1, nw = 1;
        for (int xi = i; i < 400-n && xi < i+n; xi++) {
            x *= grid[xi];
        }
        if (products[0] < x) {
            products[0] = x;
        }
        for (int yi = i; i < 400-20*(n-1) && yi < i+20*n; yi += 20) {
            y *= grid[yi];
        }
        if (products[1] < y) {
            products[1] = y;
        }
        for (int nei = i; i >= n-1 && i % 20 >= n-1 && i < 400-20*(n-1) && nei < i+20*n-n; nei += 19) {
            ne *= grid[nei];
        }
        if (products[2] < ne) {
            products[2] = ne;
        }
        for (int nwi = i; i < 400-20*(n-1)-(n-1) && i % 20 <= 20-n && nwi < i+20*n+n; nwi += 21) {
            nw *= grid[nwi];
        }
        if (products[3] < nw) {
            products[3] = nw;
        }
    }
    llu maxp = 0;
    for (auto p : products) {
        if (maxp < p) {
            maxp = p;
        }
    }
    cout << maxp << endl;
    return 0;
}
