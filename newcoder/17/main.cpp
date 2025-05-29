#include <iostream>

int main() {
    int n;
    while (scanf("%d", &n)!=EOF) {
        long long d = 1;
        for (int i = 1; i <= n; i++) {
            d *= i;
        }
        printf("%lld", d);
    }
    return 0;
}
