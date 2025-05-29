#include <iostream>
#include <string.h>

using namespace std;

long long toDigit(char x[], int m){
    int length = strlen(x);
    long long y = 0, product = 1;
    for (int i = length-1; i >= 0; i--) {
        int v = 0;
        if ('0'<=x[i] && x[i]<='9') {
            v = x[i]-'0';
        } else {
            v = tolower(x[i]) - 'a' + 10;
        }
        y += v * product;
        product *= m;
    }
    return y;
}

void fromDigit(long long x, int n){
    char z[40];
    int num = 0;
    do{
        int v = x % n;
        char c = '0';
        if (v<=9){
            c = '0'+v;
        } else {
            c = 'a'+v-10;
        }
        z[num++] = c;
        x = x/n;
    }while(x != 0);
    for (long long i = num-1; i >=0 ; --i) {
        printf("%c", z[i]);
    }
    printf("\n");
}

int main() {
    int m, n;
    char x[100];
    scanf("%d%d%s", &m, &n, x);
    long long y = toDigit(x, m);
    fromDigit(y, n);
    return 0;
}

//36 9
//XYZZA765