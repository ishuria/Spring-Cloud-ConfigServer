#include <iostream>
using namespace std;

long long root(long long x, long long y, long long k){
    if (y==0){
        return 1;
    }
    if (y%2==1) {
        long long z = root(x, y/2, k);
        z %= (k-1);
        return z * z * (x%(k-1)) % (k-1);
    }
    long long z = root(x, y/2, k);
    z %= (k-1);
    return z * z % (k-1);
}

int main() {
    long long x, y, k;
    scanf("%lld%lld%lld", &x, &y, &k);
    long long z = root(x, y, k);
    printf("%lld", z?z:k-1);
//    long z=1;
//
//    while (y){
//        x %=(k-1);
//        if (y%2==1){
//            z *=x;
//            z %=(k-1);
//        }
//        x *= x;
//        y/=2;
//    }
//    if (z%(k-1)==0){
//        printf("%lld\n", k-1);
//    }else {
//        printf("%lld\n", z%(k-1));
//    }
    return 0;
}
//799043235 80380325 8
//295150688 600154635 8