#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m)!=EOF) {
        while (n!=m) {
            if (n>m){
                n /=2;
            } else {
                m/=2;
            }
        }
        printf("%d\n",n);
    }
    return 0;
}
