#include <iostream>

struct node{
    node *left;
    node *right;
    int v;
};

node* insert(node *root, int val){
    if (root== nullptr){
        root = new node();
        root->v=val;
        return root;
    }
    if (root->v==val) {
        return root;
    }
    if (root->v>val){
        root->left=insert(root->left, val);
    } else {
        root->right=insert(root->right, val);
    }
    return root;
}

void inorder(node *root){
    if (root== nullptr){
        return;
    }
    inorder(root->left);
    printf("%d ", root->v);
    inorder(root->right);
}

void preorder(node *root){
    if (root== nullptr){
        return;
    }
    printf("%d ", root->v);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if (root== nullptr){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->v);
}

int main() {
    int n;
    while (scanf("%d", &n)!=EOF) {
        int val;
        node* root = nullptr;
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            root = insert(root, val);
        }
        preorder(root);
        printf("\n");
        inorder(root);
        printf("\n");
        postorder(root);
        printf("\n");
    }
    return 0;
}
