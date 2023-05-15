#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}linklist;

int main(){
    int num,i,j;
    scanf("%d",&num);
    linklist *plist,*p,*s,*q;
    plist=(linklist*)malloc(sizeof(LNode));
    plist->next=plist;
    scanf("%d",&plist->data);
    p=plist;
    for(i=1;i<num;i++){ 
        getchar();
        q=(linklist*)malloc(sizeof(LNode));
        q->next=plist;
        p->next=q;
        scanf("%d",&q->data);
        p=q;
    }
    for(i=1;i<num;i++){
        printf("%d,",plist->data);
        plist=plist->next;
    }
    printf("%d",plist->data);
    return 0;
}