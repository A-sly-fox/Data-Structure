#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    char chdata;
    struct LNode *succ;
    struct LNode *next;
}linklist;
void getnext(linklist *plist,int next[],int len);

int main(){
    int len1,len2;
    scanf("%d %d\n",&len1,&len2);
    int next[len2];
    linklist *plist1,*plist2,*p,*q,*pi,*pj;
    plist1=(linklist*)malloc(sizeof(LNode));
    plist1->next=NULL;
    plist1->succ=NULL;
    p=plist1;
    for(int i=0;i<len1;i++){
        q=(linklist*)malloc(sizeof(LNode));
        q->chdata=getchar();
        q->next=p;
        q->succ=NULL;
        p->succ=q;
        p=q;
    }
    getchar();
    plist2=(linklist*)malloc(sizeof(LNode));
    plist2->next=NULL;
    plist2->succ=NULL;
    p=plist2;
    for(int i=0;i<len2;i++){
        q=(linklist*)malloc(sizeof(LNode));
        q->chdata=getchar();
        q->next=p;
        q->succ=NULL;
        p->succ=q;
        p=q;
    }
    getnext(plist2,next,len2);
    int i,j;
    i=j=0;
    pi=plist1->succ;
    while(i<len1 && j<len2){
        p=plist2->succ;
        for(int q=0;q<j;q++){
            p=p->succ;
        }
        pj=p;
        if(j==-1 || pi->chdata==pj->chdata){
            pi=pi->succ;
            i++;j++;
        }else{
            j=next[j];
        }
    }
    if(j>=len2)
        printf("%d\n",i-len2);
    else
        printf("-1");
    return 0;
}

void getnext(linklist *plist,int next[],int len){
    int j=0,k=-1;
    linklist *p,*jplist,*kplist;
    next[0]=-1;
    while(j<len){
        p=plist->succ;
        for(int i=0;i<j;i++){
            p=p->succ;
        }
        jplist=p;
        p=plist->succ;
        for(int i=0;i<k;i++){
            p=p->succ;
        }
        kplist=p;
        if(k==-1 || jplist->chdata==kplist->chdata){
            j++;k++;
            next[j]=k;
        }else{
            k=next[k];
        }
    }
}