#include <iostream>
#include <string>

using namespace std;

struct node {
    char v;
    node *left;
    node *right;
};

node* build(string s, int &index) {
    if (s[index]=='#') {
        index++;
        return nullptr;
    }
    node *p = new node();
    p->v = s[index];
    index++;
    p->left = build(s, index);
    p->right = build(s, index);
    return p;
}

void inorder(node* p){
    if (p== nullptr) {
        return;
    }
    inorder(p->left);
    printf("%c ", p->v);
    inorder(p->right);
}

int main() {
    char s[105];
    while (scanf("%s", s)!=EOF) {
        int index = 0;
        node *p = build(s, index);
        inorder(p);
        printf("\n");
    }
    return 0;
}


// abc##de#g##f###

