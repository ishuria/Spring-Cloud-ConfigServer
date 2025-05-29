#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    string name;
    vector<node> v;
};

bool cmp(node n1, node n2){
    return n1.name < n2.name;
}

vector<node> ans;

void process(string s){
    if (s[s.size()-1]=='\\') {
        s = s.substr(0, s.size()-1);
    }
    vector<node> *t = &ans;
    int i = 0;
    for (int j = i; j < s.size(); j++) {
        if (s[j]=='\\') {
            string name = s.substr(i, j-i);

            int index = -1;
            for (int k = 0; k < t->size(); k++) {
                if ((*t)[k].name == name){
                    index = k;
                }
            }

            if (index == -1){
                node temp;
                temp.name = name;

                t->push_back(temp);
                t = &(*t)[t->size()-1].v;
            } else {
                t = &(*t)[index].v;
            }
            i = j+1;
        }
    }

    string name = s.substr(i, s.size());

    int index = -1;
    for (int k = 0; k < t->size(); k++) {
        if ((*t)[k].name == name){
            index = k;
        }
    }

    if (index == -1){
        t->push_back({name});
    }
}

void print(vector<node> ans, string prefix){
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++) {
        printf("%s%s\n", prefix.c_str(), ans[i].name.c_str());
        print(ans[i].v, "  "+prefix);
    }
}

int main() {
    int n;
    while (scanf("%d", &n)!=EOF && n !=0) {
        ans.clear();
        string s[n];
        for (int i = 0; i < n; i++) {
            cin>>s[i];
            process(s[i]);
        }
        print(ans, "");
        printf("\n");
    }
    return 0;
}


/*
10
N\W\L\R\B\B\M\Q\B\H\C\D\A\R\Z\O\W\K\K\Y\
H\I\D\D\Q\S\C\D\X\R\J\M\O\W\F\R\X\S\J\Y\
B\L\D\B\E\F\S\A\R\C\B\Y\N\E\C\D\Y\G\G\X\
X\P\K\L\O\R\E\L\L\N\M\P\A\P\Q\F\W\K\H\O\
P\K\M\C\O\Q\H\N\W\N\K\U\E\W\H\S\Q\M\G\B\
B\U\Q\C\L\J\J\I\V\S\W\M\D\K\Q\T\B\X\I\X\
M\V\T\R\R\B\L\J\P\T\N\S\N\F\W\Z\Q\F\J\M\
A\F\A\D\R\R\W\S\O\F\S\B\C\N\U\V\Q\H\F\F\
B\S\A\Q\X\W\P\Q\C\A\C\E\H\C\H\Z\V\F\R\K\
M\L\N\O\Z\J\K\P\Q\P\X\R\J\X\K\I\T\Z\Y\X\
*/