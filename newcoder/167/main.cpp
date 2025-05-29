#include <iostream>

using namespace std;

struct bign{
    int len;
    int d[500];
    bign(){
        len=0;
        fill(d, d + 500, 0);
    }
};

bign add (bign a, bign b) {
    bign c;
    int l = max(a.len, b.len);
    int carry = 0;
    for (int i = 0; i < l; i++) {
        carry += a.d[i]+b.d[i];
        c.d[c.len++] = carry%10;
        carry /= 10;
    }
    if (carry!=0){
        c.d[c.len++] = carry%10;
    }
    return c;
}

void print(bign a){
    for (int i = a.len-1;i>=0;i--) {
        printf("%d", a.d[i]);
    }
    printf("\n");
}

int main() {
    int a, n;
    while (scanf("%d %d", &a, &n)!=EOF) {
        bign ans;
        ans.len=1;
        ans.d[0]=0;
        for (int i = 1; i <= n;i++) {
            bign t;
            t.len=i;
            for (int j = 0; j < i; j++) {
                t.d[j]=a;
            }
            ans = add(ans, t);
        }
        print(ans);
    }
    return 0;
}
