#include <iostream>
#include <set>
#include <string.h>
#include <string>

using namespace std;

bool used[10];

set<string> ans;

void dfs(char s[], int index, int len, string str){
    int n = strlen(s);
    if (len == n-1) {
        ans.insert(str+s[index]);
        return;
    }
    str += s[index];
    used[index]=true;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(s, i, len+1, str);
        }
    }
    used[index]=false;
}


void solve(char s[]){
    int n = strlen(s);

    for (int i = 0; i < n; ++i) {
        dfs(s, i, 0, "");
    }

    for (set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout<<*it<<endl;
    }
}


int main() {
    char s[10];
    while (scanf("%s", s)!=EOF) {
        solve(s);
    }
    return 0;
}
