#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef  struct  BSTNode{  
    int data;
    struct  BSTNode  *lchild , *rchild;
} BSTNode, *BSTree;

void insert(BSTNode *p, int data){
    if(p->data == data){
        printf("%d has already existed!\n",data);
    }else if(p->data < data){
        if(p->rchild == NULL){
            p->rchild = (BSTNode *)malloc(sizeof(BSTNode));
            p->rchild->data = data;
            p->rchild->lchild = p->rchild->rchild = NULL;
        }else
            insert(p->rchild,data);
    }else{
        if(p->lchild == NULL){
            p->lchild = (BSTNode *)malloc(sizeof(BSTNode));
            p->lchild->data = data;
            p->lchild->lchild = p->lchild->rchild = NULL;
        }else
            insert(p->lchild,data);
    }
}

void myprint(BSTNode *p){
    if(!p)
        return;
    myprint(p->lchild);
    printf("%d ",p->data);
    myprint(p->rchild);
}

int main(){
    BSTNode *root,*p,*head;
    int length1 = 0,length2 = 0,data1[max],data2[max];
    char c = ' ';
    while(c != '\n'){
        scanf("%d",&data1[length1++]);
        c = getchar();
    }
    c = ' ';
    while(c != '\n'){
        scanf("%d",&data2[length2++]);
        c = getchar();
    }
    root = (BSTNode *)malloc(sizeof(BSTNode));
    root->data = data1[0];
    root->lchild = root->rchild = NULL;
    for(int i = 1;i < length1;i++){
        if(data1[i] != -1)
            insert(root,data1[i]);
    }
    for(int i = 0;i < length2;i++){
        if(data2[i] != -1)
            insert(root,data2[i]);
    }
    myprint(root);
    return 0;
}