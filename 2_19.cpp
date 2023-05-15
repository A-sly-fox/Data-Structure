#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct LNode{
    int data;
    struct LNode *next;
}linklist;

int main(){
    int data[MAX],i=0,j,mink,maxk;
    char c=' ';
    while(c!='\n'){
        scanf("%d",&data[i]);
        c=getchar();
        i++;
    }
    scanf("%d %d",&mink,&maxk);
    linklist *plist,*p,*q,*r;
    q=NULL;
    for(j=0;j<i;j++){
        p=(linklist*)malloc(sizeof(LNode));
        p->data=data[i-1-j];
        p->next=q;
        q=p;
    }
    plist=(linklist*)malloc(sizeof(LNode));
    plist->next=q;
    q=plist;
    while(q->next!=NULL){
        p=q->next;
        if(p->data>mink && p->data<maxk){
            q->next=p->next;
            free(p);
        }else
            q=q->next;
    }
    q=plist->next;
    while(q!=NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    return 0;
}