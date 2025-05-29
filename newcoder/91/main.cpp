#include <iostream>
using namespace std;

char t[1000010];
char p[1000010];
int d[1000010];

void getNext(char p[], int len){
    d[0]=-1;
    int j = -1;
    for (int i = 1; i < len; i++) {
        while (j!=-1&&p[i]!=p[j+1]) {
            j=d[j];
        }
        if (p[i]==p[j+1]) {
            j++;
        }
        d[i]=j;
    }
}

int kmp(char t[], char p[]){
    int n = strlen(t);
    int m = strlen(p);
    int j = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (j!=-1&&t[i]!=p[j+1]) {
            j = d[j];
        }
        if (t[i]==p[j+1]){
            j++;
        }
        if(j==m-1){
            ans++;
        }
    }
    return ans;
}

int main() {
    fill(t, t+1000010,0);
    fill(p, p+1000010,0);
    fill(d, d+1000010,0);
    while (scanf("%s%s", t, p)!=EOF) {
        getNext(p, strlen(p));
        printf("%d\n", kmp(t, p));
        fill(t, t+1000010,0);
        fill(p, p+1000010,0);
        fill(d, d+1000010,0);
    }
    return 0;
}
