#include <iostream>

void longToC(long a, int m){
    char ans[50];
    int num = 0;
     do {
        ans[num++]='0'+(a%m);
        a /= m;
    }while (a!=0);
    for (int i = num-1; i >= 0 ; --i) {
        printf("%c", ans[i]);
    }
    printf("\n");
}

int main() {
    int m;
    while (scanf("%d", &m)!=EOF){
        if (m==0) {
            return 0;
        }
        int a, b;
        scanf("%d%d", &a, &b);
        long c = a + b;
        longToC(c, m);
    }
    return 0;
}
