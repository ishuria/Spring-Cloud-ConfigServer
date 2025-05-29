#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

char pattern[5]={'2','0','1','2','\0'};
struct node {
    char s[13];
    int level;
};


void getNext(const char s[],int len, int next[]){
    int j = -1;
    next[0] = -1;  //init
    for(int i = 1; i < len ; i++){   //求解next[1] ~ next[len - 1]
        while(j != -1 && s[i] != s[j+1] ){
            j = next[j];
        }
        if(s[i] == s[j+1]){
            j++;     //j指向next[i]
        }
        next[i] = j;
    }
}

int match(char s[], char pattern[]){
    int n = strlen(s);
    int m = strlen(pattern);
    int next[m];
    getNext(pattern, m, next);

    int j = -1;
    for (int i = 0; i < n; i++) {
        while(j!=-1&&s[i]!=pattern[j+1]){
            j = next[j];
        }
        if (s[i]==pattern[j+1]) {
            j++;
        }
        if(j==m-1){
            return i-j;
        }
    }
    return -1;
}


int bfs(char s[]){
    set<string> discovered; // 记录是否已经在图里
    discovered.insert(s);
    queue<node> q;
    q.push({s, 0});
    while (!q.empty()) {
        node ss = q.front();
        q.pop();
        for (int i = 0; i < ss.s.size()-1; i++) {
            string sss = ss.s;
            char t = sss[i];
            sss[i] = sss[i+1];
            sss[i+1] = t;
            if (discovered.find(sss)!=discovered.end()){
                continue;
            }
            if(match(s, pattern)>=0){
                return ss.level+1;
            }
            discovered.insert(sss);
            q.push({sss, ss.level+1});
        }
    }
    return -1;
}


int main() {
    int n;

    while (scanf("%d", &n)!=EOF){
        char s[13];
        scanf("%s", s);
        if(match(s, pattern)>=0){
            printf("0");
            continue;
        }
        printf("%d", bfs(s));
    }
    return 0;
}
