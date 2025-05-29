#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000;

// d[i][j] = min(d[i-1][m], d[i-1][m-s[i]] + 1)
int main() {
    int m, n;
    while (scanf("%d%d", &m, &n)!=EOF) {
        int s[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }

        int d[n+1][m+1];

        fill(d[0], d[0] + m * n, MAX);

        for (int i = 0; i < n; i++) {
            d[i][0] = 0;
        }

        for (int j = 0; j < m; j++) {
            d[0][j] = MAX;
        }

        d[0][0]=0;

        int ans = MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                d[i][j] = min(d[i-1][j], d[i-1][j-s[i-1]] + 1);
                ans = min(ans, d[i][j]);
            }
        }
        if (d[n][m]>m) {
            printf("%d", 0);
        } else {
            printf("%d", d[n][m]);
        }
    }
    return 0;
}


/**
10
5
1 3 3 3 4
**/