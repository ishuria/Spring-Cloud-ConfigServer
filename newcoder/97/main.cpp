#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct bign{
    int len;
    int d[50];
    bign(){
        len=0;
        fill(d, d+50, 0);
    }
};

bign intTobign(int d){
    bign a;
    do{
        a.d[a.len++]=d%10;
        d/=10;
    }while (d!=0);
    return a;
}

bign add(bign a, bign b){
    bign c;
    int len = max(a.len, b.len);
    int carry = 0;
    for (int i = 0; i < len; i++) {
        carry += a.d[i]+b.d[i];
        c.d[c.len++]= carry %10;
        carry /= 10;
    }
    if (carry!=0){
        c.d[c.len++]= carry;
    }
    return c;
}

bign reverse(bign a){
    int i = 0;
    int j = a.len-1;
    while (i < j) {
        int t = a.d[i];
        a.d[i]=a.d[j];
        a.d[j]=t;
        i++;
        j--;
    }
    return a;
}

bool eq(bign a, bign b){
    if (a.len!=b.len){
        return false;
    }

    for (int i = 0; i < a.len; i++) {
        if (a.d[i]!=b.d[i]){
            return false;
        }
    }
    return true;
}

void print(bign a){
    for (int i = a.len-1;i>=0;i--) {
        printf("%d", a.d[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m)!=EOF) {
        bign bn = intTobign(n);
        bign bm = intTobign(m);
        bign bs = add(bn, bm);
        bign br = reverse(bs);

        bign bnr = reverse(bn);
        bign bmr = reverse(bm);
        bign brs = add(bnr, bmr);

        if (eq(br, brs)) {
            print(bs);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
