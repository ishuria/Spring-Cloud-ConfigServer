#include <iostream>

using namespace std;

struct node {
    int v;
    node *next;
};

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 0; i< m ; i++){
        int n;
        scanf("%d", &n);
        node *dummy = new node();
        node *tail = nullptr;
        for (int j = 1; j <= n;j++){
            node *t=new node();
            t->v = j;
            if (tail== nullptr){
                dummy->next=t;
                tail=t;
                t->next=t;
            } else {
                tail->next=t;
                t->next=dummy->next;
                tail=tail->next;
            }
        }
        int counter = 1;
        node*t=dummy->next;
        node *pre=dummy;
        while (dummy->next!= nullptr) {
            if (counter%3==0) {
                if (pre->next==pre) {
                    printf("%d\n", t->v);
                    break;
                }
                pre->next=t->next;
                counter=1;
                printf("%d ", t->v);
                t=pre->next;
            }
            counter +=1;
            t=t->next;
            pre=pre->next;
        }
    }
    return 0;
}
/*
 *
2
42
18
*/