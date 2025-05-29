#include <iostream>

using namespace std;
struct button {
    int g;
    int t;
} b[26] = {
        {1,1},
        {1,2},
        {1,3},

        {2,1},
        {2,2},
        {2,3},

        {3,1},
        {3,2},
        {3,3},

        {4,1},
        {4,2},
        {4,3},

        {5,1},
        {5,2},
        {5,3},

        {6,1},
        {6,2},
        {6,3},
        {6,4},

        {7,1},
        {7,2},
        {7,3},

        {8,1},
        {8,2},
        {8,3},
        {8,4},
};



int main() {
    char s[105];
    while (scanf("%s", s)!=EOF) {
        int ans = 0;
        for (int i = 0; i < strlen(s); i++) {
            ans += b[s[i] - 'a'].t;
//            printf("%c\n", s[i]);
//            printf("%d\n", b[s[i] - 'a'].t);
            if (i >= 1) {
                if (b[s[i]-'a'].g==b[s[i-1]-'a'].g){
                    ans+=2;
                } else {
//                    ans+=1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
