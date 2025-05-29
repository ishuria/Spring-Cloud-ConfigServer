#include <iostream>
#include <string.h>

using namespace std;

const int MAXN = 1000010;

int d[MAXN][16];

int FindM(int n){
    int m = 1;
    while (m * 2 <= n) {
        m *= 2;
    }
    return m;
}

int kth(int n){
    int m = 1;
    int k = 0;
    while (m * 2 <= n) {
        m *= 2;
        k++;
    }
    return k;
}

// 1000000
//1000000000

int solve(int n, int m){
    int k = kth(m);
    if (d[n][k]!=0) {
        return d[n][k];
    }
    if (n == 1 || m == 1){
        return 1;
    }
    if (n==m) {
        return d[n][k] = (1 + solve(n, n/2)) % 1000000000;
    }
    if (n < m) {
        return d[n][k] = (solve(n, FindM(n))) % 1000000000;
    }
    return d[n][k] = ((solve(n-m, m)) % 1000000000 + (solve(n, m/2)) % 1000000000) % 1000000000;
}

int main() {
    memset(d, 0, sizeof d);
    int n;
    scanf("%d", &n);
    printf("%d", solve(n, FindM(n)));
    return 0;
}

