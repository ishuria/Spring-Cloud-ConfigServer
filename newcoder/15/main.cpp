#include <iostream>
#include <vector>

using namespace std;

int charToInt(char s[3]){
    int ans = 0;
    for (int i = 0; i <3; i++) {
        ans = ans * 10 + s[i]-'0';
    }
    return ans;
}

vector<char> intToChar(int d){
    vector<char> r, ans;
    while (d != 0){
        r.push_back(d % 10 + '0');
        d /= 10;
    }
    while (r.size()<3){
        r.push_back('0');
    }
    for (int i = r.size()-1; i >= 0; i--) {
        ans.push_back(r[i]);
    }
    return ans;
}

int main() {

    for (int i = 0; i <= 532; i++) {
        int j = 532-i;
        vector<char> v1 = intToChar(i);
        vector<char> v2 = intToChar(j);
        if (v1[1]==v2[0] && v1[2]==v2[1] && v1[2]==v2[2]) {
            printf("%c %c %c\n", v1[0], v1[1], v1[2]);
        }
    }

    return 0;
}

// abc+bcc=532