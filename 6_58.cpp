#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int L[MAX];
int R[MAX];
int L2[MAX];
int R2[MAX];
typedef enum PointerThr {LINK,Thread} PointerThr;
typedef struct BiThrNode {
    int data;
    struct BiThrNode *lchild,*rchild;
    PointerThr LTag, RTag;
} BiThrNode, *BiThrTree;

BiThrNode *p,*pre,*pp;

void InThreading(BiThrNode *p){
    if(p){
        InThreading(p->lchild);
        if(!p->lchild) {
            p->LTag = Thread;  
            p->lchild = pre;
        }
        if(!pre->rchild) { 
            pre->RTag = Thread; 
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild); 
   }
}

void inorderThreading(BiThrNode *Thrt, BiThrNode *T){
    Thrt->LTag= LINK;
    Thrt->RTag= Thread;
    Thrt->rchild = Thrt;
    if (!T)
        Thrt->lchild = Thrt;
    else{
        Thrt->lchild = T;
        pre = Thrt;
        InThreading(T);
        pre->rchild = Thrt;
        pre->RTag = Thread;
        Thrt->rchild = pre;
    } 
    return;
}


void createtree(int *a,int *b,BiThrNode *root,int offset){
    int valueroot=root->data;
    BiThrNode *p;
    if(!a[valueroot-offset]){
        root->lchild=NULL;
    }else{
        p=(BiThrNode *)malloc(sizeof(BiThrNode));
        p->data=a[valueroot-offset];
        root->lchild=p;
        root->LTag=LINK;
        createtree(a,b,p,offset);
    }
    if(!b[valueroot-offset]){
        root->rchild=NULL;
    }else{
        p=(BiThrNode *)malloc(sizeof(BiThrNode));
        p->data=b[valueroot-offset];
        root->rchild=p;
        root->RTag=LINK;
        createtree(a,b,p,offset);
    }
}

int main(){
    char c=' ';
    int a,b,num=0,signal=0,d[MAX];
    BiThrNode *root,*Thrt,*root2,*Thrt2;
    for(int i=0;i<MAX;i++){
        scanf("%d",&L[i]);
        c=getchar();
        if(c=='\n')
            break;
    }
    for(int i=0;i<MAX;i++){
        scanf("%d",&R[i]);
        c=getchar();
        if(c=='\n')
            break;
    }
    scanf("%d",&a);
    getchar();
    root=(BiThrNode *)malloc(sizeof(BiThrNode));
    Thrt=(BiThrNode *)malloc(sizeof(BiThrNode));
    root->data=L[0];
    createtree(L,R,root,L[0]-1);
    inorderThreading(Thrt, root);
    for(int i=0;i<MAX;i++){
        scanf("%d",&L2[i]);
        c=getchar();
        if(c=='\n')
            break;
    }
    for(int i=0;i<MAX;i++){
        scanf("%d",&R2[i]);
        c=getchar();
        if(c=='\n')
            break;
    }
    root2=(BiThrNode *)malloc(sizeof(BiThrNode));
    Thrt2=(BiThrNode *)malloc(sizeof(BiThrNode));
    root2->data=L2[0];
    createtree(L2,R2,root2,L2[0]-1);
    inorderThreading(Thrt2, root2);
    pre=Thrt;
    p = Thrt->lchild;
    while(p!=Thrt){
        while (p->LTag==LINK){
            pre = p;
            p = p->lchild;
        }
        if(p->data==a)
            break;
        while (p->RTag==Thread && p->rchild!=Thrt){
            pre = p;
            p = p->rchild;
            if(p->data==a)
                signal++;
        }
        if(signal)
            break;
        pre = p;
        p = p->rchild;
    }
    pp=root2;
    while (pp->LTag==LINK){
        pp = pp->lchild;
    }
    if(p->LTag==LINK){
        root2 -> rchild = p->lchild;
        root2->RTag=LINK;
        p->lchild = root2;
    }
    else{
        pp->lchild=p->lchild;
        p->lchild = root2;
        p->LTag=LINK;
        root2->rchild = p;
    }
    p = Thrt->lchild;
    while(p!=Thrt){
        while (p->LTag==LINK) 
            p = p->lchild;
        d[num++]=p->data;
        while (p->RTag==Thread && p->rchild!=Thrt){
            p = p->rchild;
            d[num++]=p->data;
        }
        p = p->rchild;
    }
    for(int i=0;i<num;i++){
        printf("%d",d[i]);
        printf((i==num-1)?"":" ");
    }
    return 0;
}