#include <iostream>

using namespace std;

int main() {
    char s[4];
    while (scanf("%s", s)!=EOF) {
        int i = 0, j = 3;
        while (i <= j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
        printf("%s\n", s);
    }
    return 0;
}
