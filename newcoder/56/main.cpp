#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<char> longToM(long num, int m){
    vector<char> ans;
    int len = 0;
    while (num!=0){
        int v = num%m;
        if (v>=10){
            ans.push_back('a'+v-10);
        } else {
            ans.push_back('0'+v);
        }
        num/=m;
    }
    return ans;
}

long nToLong(char n[], int a){
    long ans = 0;
    int len = strlen(n);
    int p = 1;
    for (int i = len-1; i >=0 ; --i) {
        char c = n[i];
        int v = 0;
        if (c >= '0' && c <= '9') {
            v = c-'0';
        } else {
            v = 10 + tolower(c) - 'a';
        }
        ans += v * p;
        p *= a;
    }
    return ans;
}


int main() {
    int a, b;
    char n[500];
    scanf("%d %s %d", &a, n, &b);
    long l = nToLong(n, a);
    vector<char> ans = longToM(l, b);
    for (int i = ans.size()-1; i >=0; --i) {
        printf("%c", toupper(ans[i]));
    }
    printf("\n");
    return 0;
}
