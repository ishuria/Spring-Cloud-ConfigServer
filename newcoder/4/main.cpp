#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;

    while (scanf("%d", &n)!=EOF) {

        // proxy set
        set<string> s;

        // matched proxy set
        set<string> p;

        for (int i = 0; i < n; i++) {
            char c[20];
            scanf("%s", c);
            s.insert(c);
        }

        scanf("%d", &m);
        vector<string> t;


        for (int i = 0; i < m; i++) {
            char c[20];
            scanf("%s", c);
            t.push_back(c);
        }


        if (n==1){
            int ans = 0;
            for (int i = 0; i < m; i++) {
                if (s.find(t[i])!=s.end()) {
                    ans = -1;
                }
            }
            printf("%d", ans);
            continue;
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            if (s.find(t[i])!=s.end()){
                p.insert({t[i]});
                if(p.size() == n) {
                    ans++;
                    p.clear();
                    p.insert({t[i]});
                    continue;
                }
            }
        }

        printf("%d", ans);

    }

    return 0;
}

