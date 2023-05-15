#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct node{
    int key;
    struct node *next;
}Node;

int search[max];

int main(){
    Node *h,*t,*p;
    char c = ' ';
    int a,i=0,b;
    scanf("%d", &a);
    p = (Node *)malloc(sizeof(Node));
    p->next = p;
    p->key = a;
    t = p;
    h = p;
    c = getchar();
    while(c != '\n'){
        scanf("%d", &a);
        c = getchar();
        p = (Node *)malloc(sizeof(Node));
        p->key = a;
        t->next = p;
        p->next = h;
        t = p;
    }
    t=h;
    c=' ';
    while(c != '\n' && c != EOF){
        scanf("%d", &a);
        c = getchar();
        search[i++] = a;
    }
    for(int j=0;j<i;j++){
        b=t->key;
        a=b;
        if(search[j]==b){
            printf("1");
            printf((j==i-1)?"":" ");
            continue;
        }
        while(1){
            t=t->next;
            a=t->key;
            if(a==b){
                printf("0");
                break;
            }
            if(search[j]==a){
                printf("1");
                break;
            }
        }
        printf((j==i-1)?"":" ");
    }
    return 0;
}