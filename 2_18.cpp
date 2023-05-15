#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct LNode{
    int data;
    struct LNode *next;
}linklist;

int main(){
    int data[MAX],i,j,num;
    char c=' ';
    i=j=0;
    while(c!='\n'){
        scanf("%d",&data[i]);
        c=getchar();
        i++;
    }
    scanf("%d",&num);
    linklist *p,*s,*q;
    p=(linklist*)malloc(sizeof(LNode));
    p->data=data[0];
    s=p;
    for(j=1;j<i;j++){
        q=(linklist*)malloc(sizeof(LNode));
        q->data=data[j];
        q->next=NULL;
        p->next=q;
        p=q;
    }
    j=0;
    q=s;
    while(j < num-1 && q -> next){
        q = q -> next;
        ++j;
    }
    if(num!=0){
        p = q -> next;            
        q -> next = p -> next;
        free(p);
    }else if(num == 0){
        p = s;
        s = p -> next;
        free(p);
    }
    if(i==1){
        printf("NULL");
        return 0;
    }
    while(s!=NULL){
        printf("%d ",s->data);
        s=s->next;
    }
    return 0;
}
