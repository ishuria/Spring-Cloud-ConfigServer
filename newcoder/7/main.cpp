#include <iostream>
using namespace std;
struct factor{
    int val;
    int count;
} fac[100000];
// 600154635
bool isPrime(int n){
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrime(){
    int num = 0;
    int index = 2;
    while (true) {
        if (isPrime(index)){
            fac[num].val = index;
            fac[num].count = 0;
            num++;
        }
        if (num >= 100000) {
            return;
        }
        index++;
    }
}

int main() {
    findPrime();
    int n;
    while (scanf("%d", &n)!=EOF) {
        if (n == 1) {
            printf("%d\n", 0);
            continue;
        }
        int ans = 0;
        if (n > 1) {
            for (int i = 0; i < 100000; i++) {
                if (n % fac[i].val == 0){
                    while (n % fac[i].val == 0) {
                        n /= fac[i].val;
                        ans++;
                    }
                }
            }
        }
        if (n > 1) {
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
