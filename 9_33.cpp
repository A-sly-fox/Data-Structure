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

void judge(Tree *p,int x){
    if(p == NULL)
        return;
    else if(p->data >= x){
        result[num++] = p->data;
        judge(p->lchild,x);
        judge(p->rchild,x);
    }else{
        judge(p->rchild,x);
    }   
}

int main(){
    Tree *p,*head;
    head = (Tree *)malloc(sizeof(Tree));
    int a,count = 0, x;
    char c = ' ';
    while(c != '\n'){
        scanf("%d", &data[count++]);
        c= getchar();
    }
    scanf("%d", &x);
    createtree(head,0,count);
    judge(head,x);
    int max;
    int d;
    for(int i = 0; i < num; i++){
        max = 0x80000000;
        for(int i = 0; i < num; i++){
            if(result[i] > max){
                max = result[i];
                d = i;
            }
        }
        result[d] = 0x80000000;
        printf("%d",max);
        printf((i != num-1)?" ":"");
    }
    return 0;
}