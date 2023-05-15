#include<stdio.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX];
int sp=0;

typedef struct TriTNode {
    char data;
    struct TriTNode *lchild,*rchild;
    struct TriTNode *parent;
}TriTree; 

void push(char f){
    if(sp<MAX)
        stack[sp++]=f;
    else
        printf("error:stack full, can't push %g\n",f);
}

char pop(void){
    if(sp>0)
        return stack[--sp];
    else{
        printf("error:stack empty\n");
        return 0;
    }
}

int main(){
    TriTree *p,*plist,*q;
    char c;
    c=getchar();
    plist=(TriTree*)malloc(sizeof(TriTNode));
    plist->data=c;
    p=q=plist;
    push(c);
    while((c=getchar())!='\n'){
        while(1){
            if(q->lchild!=NULL){
                if(c=='^'){
                    q->lchild=NULL;
                }else{
                    p=(TriTree*)malloc(sizeof(TriTNode));
                    q->lchild=p;
                    p->data=c;
                    p->parent=q;
                }
                break;
            }else if(q->rchild!=NULL){
                if(c=='^'){
                    q->rchild=NULL;
                }else{
                    p=(TriTree*)malloc(sizeof(TriTNode));
                    q->rchild=p;
                    p->data=c;
                    p->parent=q;
                }
                break;
            }else{
                q=q->parent;
            }
        }
    }
    return 0;
}