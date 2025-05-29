#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    int a1, a2;
    scanf("%d%d", &a1, &a2);
    int b1, b2;
    scanf("%d%d", &b1, &b2);

    int l= a2-a1+1 + b2-b1+1;
    int c[l];

    int i= a1-1,j=b1-1,k=0;

    while (i<a2){
        c[k++]=a[i++];
    }
    while (j<b2){
        c[k++]=b[j++];
    }
//    sort(c, c + l);
    printf("%d\n", c[l/2]);

    return 0;
}
