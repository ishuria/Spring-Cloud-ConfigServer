#include <iostream>
#include <vector>

using namespace std;

vector<char> intToV(int d){
    vector<char> ans;
    while (d != 0) {
        ans.push_back(d%10+'0');
        d /= 10;
    }
    return ans;
}

int solve(int a, int b){
    vector<char> va = intToV(a);
    vector<char> vb = intToV(b);

    int ans = 0;
    for (int i = 0; i < va.size(); i++) {
        for (int j = 0; j < vb.size(); j++) {
            ans += (va[i]-'0') * (vb[j]-'0');
        }
    }
    return ans;
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b)!=EOF) {
        printf("%d", solve(a, b));
    }
    return 0;
}


// 123 45