#include <iostream>
#include <string>
#include <stack>


using namespace std;

int strToInt(string s) {
    int v =0;
    for (int i = s.size()-1; i >=0 ; --i) {
        v += 10 * v + s[i]-'0';
    }
    return v;
}

string inToPost(string s) {
    string t;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
            case '+':
                while (!st.empty()) {
                    t += st.top();
                    st.pop();
                }
                st.push(s[i]);
                break;
            case '-':
                while (!st.empty()) {
                    t += st.top();
                    st.pop();
                }
                st.push(s[i]);
                break;
            case '*':
                while (!st.empty()&&(st.top()=='*'||st.top()=='/')) {
                    t += st.top();
                    st.pop();
                }
                st.push(s[i]);
                break;
            case '/':
                while (!st.empty()&&(st.top()=='*'||st.top()=='/')) {
                    t += st.top();
                    st.pop();
                }
                st.push(s[i]);
                break;
            default:
                t += s[i];
        }
    }
    while (!st.empty()){
        t += st.top();
        st.pop();
    }
    return t;
}

void solve(string str) {
    str = inToPost(str);
    stack<int> s;
    int first, second;
    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case '+':
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();
                s.push(first+second);
                break;
            case '-':
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();
                s.push(first-second);
                break;
            case '*':
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();
                s.push(first*second);
                break;
            case '/':
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();
                s.push(first/second);
                break;
            default:
                s.push(str[i]-'0');
        }
    }
    cout<<s.top()<<endl;
}

int main() {
    string s;
    while (cin>>s) {
        solve(s);
    }
    return 0;
}


// 6/2+3+3*4
// 3-7-1+3+3*6-3/1*9-9