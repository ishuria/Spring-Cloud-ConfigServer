#include <iostream>

using namespace std;

int main() {
    int n;
    int c[1005];
    fill(c, c + 1005, 0);
    int d[1005];
    fill(d, d + 1005, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        c[b]=a;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        d[b]=a;
    }

    int min = -1;
    for (int i = 0; i < 1005; ++i) {
        d[i]+=c[i];
        if (min==-1&&d[i]>0){
            min=i;
        }
    }
    for (int i = 1004; i >= 0; --i) {
        if (d[i]!=0){
            printf("%d %d", d[i], i);
            if (i==min) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }
    return 0;
}
