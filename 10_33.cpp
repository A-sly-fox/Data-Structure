#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct LNode{
    int data;
    struct LNode *next;
}linklist;

int main(){
    linklist *p,*head,*q,*r,*s,*t,*head2;
    int low=0,record,min,count=0;
    head = (linklist *)malloc(sizeof(linklist));
    head->next = NULL;
    p = head;
    while((scanf("%d",&record)) != EOF){
        q = (linklist *)malloc(sizeof(linklist));
        q->next = NULL;
        q->data = record;
        p->next = q;
        p = q;
        count++;
    }
    p = head;
    while(p->next){
        min = 0x7fffffff;
        q = p->next;
        while(q){
            if(min > q->data)
                min = q->data;
            q = q->next;
        }
        q = p;
        while(q->next){
            if(min == q->next->data){
                s = q->next;
                break;
            }
            q= q->next;
        }
        q->next = s->next;
        s->next = p->next;
        p->next = s;
        p = p->next;
    }
    p = head->next;
    for(int i=0;i<count;i++){
        printf("%d",p->data);
        printf((i==count-1)?"":" ");
        p = p->next;
    }
    return 0;
}