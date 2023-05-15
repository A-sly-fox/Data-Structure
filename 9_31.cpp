#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
int vex[MAX];
int left[MAX];
int right[MAX];
int result[MAX];
int sign = 0;

typedef struct Node {
    int data;
    struct Node *lchild,*rchild;
}Tree; 

void createtree(Tree *p, int a){
    p->data = vex[a];
    if(left[a] == -1){
        p->lchild = NULL;
    }else{
        p->lchild = (Tree *)malloc(sizeof(Tree));
        createtree(p->lchild,left[a]);
    }
    if(right[a] == -1){
        p->rchild = NULL;
    }else{
        p->rchild = (Tree *)malloc(sizeof(Tree));
        createtree(p->rchild,right[a]);
    }
}

void judge(Tree *p){
    if(p == NULL)
        return;
    Tree *q,*r;
    q = p->lchild;
    r = p->rchild;
    while((q != NULL) && (q->rchild != NULL)){
        q = q->rchild;
    }
    while((r != NULL) && (r->lchild != NULL)){
        r = r->lchild;
    }
    if((q == NULL || q->data < p->data) && (r == NULL || r->data > p->data)){
        judge(p->lchild);
        judge(p->rchild);
    }else{
        sign++;
    }
}

int main(){
    Tree *p,*head;
    head = (Tree *)malloc(sizeof(Tree));
    int count=0,point=0,num=0;
    while(scanf("%d",&vex[count]) != EOF){
        scanf("%d %d",&left[count],&right[count]);
        count++;
    }
    p = head;
    createtree(p,0);
    judge(head);
    printf((sign)?"0":"1");
    return 0;
}