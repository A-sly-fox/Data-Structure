#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct LNode{
    char data;
    struct LNode *next;
}linklist;
char record[MAX];

int main(){
    int n,i,sign=1;
    scanf("%d\n",&n);
    linklist *plist,*p,*q;
    plist=(linklist*)malloc(sizeof(LNode));
    plist->next=NULL;
    p=plist;
    for(i=0;i<n;i++){
        q=(linklist*)malloc(sizeof(LNode));
        q->data=getchar();
        q->next=NULL;
        p->next=q;
        p=q;
    }
    p=plist->next;
    i=0;
    while(p->next!=NULL){
        record[i]=p->data;
        i++;
        p=p->next;
    }
    record[n-1]=p->data;
    for(i=0;i<n;i++){
        if(record[i]!=record[n-1-i])
            sign=0;
    }
    printf("%d\n",sign);
    return 0;
}