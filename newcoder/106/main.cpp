#include <iostream>
#include <algorithm>

using namespace std;

int matrix[105][105];

int sum[105];

int shortest(int d[], int len, int k){
    int i = 0, j = 0;
    int sum = 0;
    int l = 100000;
    while (j<len) {
        sum += d[j];
        while (sum - d[i] >= k){
            sum -= d[i++];
        }
        if(sum>=k&&j-i+1<l){
            l = j-i+1;
        }
        j++;
    }
    if (l == 100000) {
        return -1;
    } else {
        return l;
    }
}

int main() {
    fill(matrix[0], matrix[0] + 105 * 105, 0);
    int n,m,k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int p = 1000000;
    for (int i = 0; i < n; i++) {
        fill(sum, sum+105, 0);
        for (int j = i; j < n; j++) {
            for (int l = 0; l < m; l++) {
                sum[l] += matrix[j][l];
            }
            int len = shortest(sum, m, k);
            if (len!=-1){
                int newP = len * (j - i + 1);
                if (newP<p) {
                    p = newP;
                }
            }
        }
    }
    if (p == 1000000) {
        printf("-1\n");
    } else {
        printf("%d\n", p);
    }
    return 0;
}

/*
 *
 *
4 4 60
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
 */