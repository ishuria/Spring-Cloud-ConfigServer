#include <iostream>
#include <math.h>

const int pNum = 10010;
int p[pNum];

bool isPrime(int n){
    if (n==1) {
        return false;
    }
    int sqr = sqrt(1.0*n);
    for (int i = 2; i <= sqr; i++) {
        if (n%i==0){
            return false;
        }
    }
    return true;
}

void find(){
    int i = 2;
    int num = 0;
    while (true) {
        if (isPrime(i)){
            p[num++]=i;
        }
        if (num==pNum) {
            break;
        }
        i++;
    }
}

int main() {
    find();
    int n;
    while (scanf("%d", &n)!=EOF) {
        printf("%d\n", p[n-1]);
    }
    return 0;
}
