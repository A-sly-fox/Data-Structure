#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
int data[MAX];
int result[MAX];
int num = 0;

typedef struct Node {
    int data;
    struct Node *lchild,*rchild;
}Tree; 

void createtree(Tree *p, int low,int high){
    if(low == high){
        p = NULL;
    }else if(low == high-1){
        p->data = data[low];
        p->lchild = NULL;
        p->rchild = NULL;
    }else{
        int mid = (low+high)/2;
        p->data = data[mid];
        if(low == mid){
            p->lchild = NULL;
        }else{
            p->lchild = (Tree *)malloc(sizeof(Tree));
            createtree(p->lchild,low,mid);
        }
        if(mid + 1 == high){
            p->rchild = NULL;
        }else{
            p->rchild = (Tree *)malloc(sizeof(Tree));
            createtree(p->rchild,mid+1,high);
        }
        
    }
}

int sign=0;
void search(Tree *p,int x,int y){
    if(p == NULL)
        return;
    if(p->data > x && p->data <y){
        search(p->lchild,x,y);
        printf((sign++)?" ":"");
        printf("%d",p->data);
        search(p->rchild,x,y);
    }else if(p->data <= x){
        search(p->rchild,x,y);
    }else if(p->data >= y){
        search(p->lchild,x,y);
    }
}

int main(){
    Tree *p,*head;
    head = (Tree *)malloc(sizeof(Tree));
    int a,count = 0, x,y;
    char c = ' ';
    while(c != '\n'){
        scanf("%d", &data[count++]);
        c= getchar();
    }
    scanf("%d %d", &x, &y);
    createtree(head,0,count);
    search(head,x,y);
    return 0;
}