#include <iostream>
#include <vector>
using namespace std;

struct fac {
    int val;
    int num;
};

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int d;
        int e = 1;
        scanf("%d", &d);
        if (d == 1) {
            printf("%d\n", 1);
            continue;
        }
        vector<fac> f;
        int dd = d;
        for (int j = 2; j * j <= dd; j++) {
            int num = 0;
            while (d % j == 0) {
                num++;
                d /= j;
            }
            if (num >= 1) {
                f.push_back({j, num});
            }
        }
        if (d != 1) {
            f.push_back({d, 1});
        }
        if (f.empty()) {
            printf("%d\n", 2);
            continue;
        } else {
            for (int j = 0; j < f.size(); j++) {
//                printf("%d %d", f[j].val, f[j].num);
                e *= (f[j].num+1);
            }
        }
        // 12
        // 1 2 3 4 6 12
        // 2 2 3

        // 3
        // 1 3

        // 4
        // 2 2
        // 3

        // 6
        // 2 3

        printf("%d\n", e);
    }
    return 0;
}