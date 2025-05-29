#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n)!=EOF) {
        int d[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &d[i]);
        }
        sort(d, d + n);
        printf("%d %d\n", d[n-1], d[0]);
    }
    return 0;
}
