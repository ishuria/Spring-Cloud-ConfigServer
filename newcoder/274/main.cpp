#include <iostream>

using namespace std;

int main() {
    int A[15]={8,8,8,8,8,10,10,10,10,18,18,18,18,18,18};
    int n = 0;
    for (int i = 0; i < 15; i++) {
        n += A[i];
    }
    bool d[15][n+1];
    fill(d[0], d[0] + 15 * (n+1), false);
    d[0][A[0]]=true;
    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < n+1; j++) {
            if (d[i-1][j]) {
                d[i][j+A[i]]=true;
                d[i][j]=true;
            }
            d[i][A[i]]=true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n+1; i++) {
        if (d[14][i]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

// 某人有8 角的邮票5 张，1 元的邮票4 张，1 元8 角的邮票6 张，用这些邮票中的一张或若干张可以得到多少中不同的邮资？