#include <iostream>
#include <vector>
using namespace std;

struct bign{
    int d[1010];
    int len;
    bign(){
        len=0;
        fill(d, d + 1010, 0);
    }
};

bign divide(bign a, int b){
    bign c;
    c.len=a.len;
    int r = 0;
    for (int i = a.len-1; i >=0 ; --i) {
        r = r * 10 + a.d[i];
        if (r>=b){
            c.d[i]=r/b;
            r %= b;
        } else {
            c.d[i]=0;
        }
    }
    while (c.len>1&&c.d[c.len-1]==0) {
        c.len--;
    }
    return c;
}

bign add(bign a, bign b){
    int n = max(a.len, b.len);bign c;
    int carry = 0;
    for (int i = 0; i < n; ++i) {
        carry += a.d[i]+b.d[i];
        c.d[c.len++] = carry%10;
        carry /= 10;
    }
    if (carry!=0) {
        c.d[c.len++] = carry%10;
    }
    return c;
}

bign multiply(bign a, int b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; ++i) {
        carry += a.d[i]*b;
        c.d[c.len++] = carry%10;
        carry/=10;
    }
    while (carry!=0) {
        c.d[c.len++] = carry%10;
        carry/=10;
    }
    return c;
}

void print(bign a){
    for (int i = a.len-1; i >=0 ; --i) {
        printf("%d", a.d[i]);
    }
    printf("\n");
}

bool isZero(bign a) {
    return a.len==1&&a.d[0]==0;
}

void print(vector<int> a){
    for (int i = 0; i < a.size(); ++i) {
        printf("%d", a[i]);
    }
    printf("\n");
}

int main() {
    char s[1010];
    scanf("%s", s);
    int n = strlen(s);
    bign a;
    for (int i = n-1; i >= 0; --i) {
        a.d[a.len++]=s[i]-'0';
    }

    vector<int> ans;
    while (!isZero(a)) {
        ans.push_back(a.d[0]%2);
        a = divide(a, 2);
    }

    bign base;
    base.d[0]=1;base.len=1;
    bign aa;
    aa.len=1;
    aa.d[0]=0;

    for (int i = ans.size()-1; i >=0 ; --i) {
        if (ans[i]==1){
            aa = add(aa, base);
        }
        base = multiply(base, 2);
    }

    print(aa);

    return 0;
}
