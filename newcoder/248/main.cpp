#include <iostream>
#include <math.h>

using namespace std;

void solve(int a, int b, int c){
    if (a == 0) {
        double x = (c * -1.0) / (b * 1.0);
        printf("x=%0.2lf\n", x);
        return;
    }
    int delta = b * b - 4 * a * c;
    if (delta == 0) {
        double x = (-1.0*b) / (2.0*a);
        printf("x=%0.2lf\n", x);
    } else if (delta > 0) {
        double sqr = sqrt(delta);
        double x1 = ((-1.0*b) + sqr) / (2.0*a);
        double x2 = ((-1.0*b) - sqr) / (2.0*a);
        printf("x1=%0.2lf,x2=%0.2lf\n", x1, x2);
    } else {
        printf("-1\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        solve(a, b, c);
    }
    return 0;
}

//x1=1.00,x2=2.00
//x=1.00
//-1