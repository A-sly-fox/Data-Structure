#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
char vex[MAX];
int left[MAX];
int right[MAX];
int result[MAX];
int sign = 0;

typedef struct Node {
    char data;
    struct Node *child,*brother;
}Tree; 

void createtree(Tree *p, int a){
    p->data = vex[a-1];
    if(left[a-1] == -1){
        p->child = NULL;
    }else{
        p->child = (Tree *)malloc(sizeof(Tree));
        createtree(p->child,left[a-1]);
    }
    if(right[a-1] == -1){
        p->brother = NULL;
    }else{
        p->brother = (Tree *)malloc(sizeof(Tree));
        createtree(p->brother,right[a-1]);
    }
}

void myprint(Tree *p,int deepth){
    if(!p)
        return;
	Tree* q = p;
	int i;
	for (i = 0; i < deepth; i++)
		printf("-");
	printf("%c\n", q->data);
	if (q->child != NULL)
		myprint(q->child, deepth + 1);
	if (q->brother != NULL)
		myprint(q->brother, deepth);
}

int main(){
    Tree *p,*head;
    head = (Tree *)malloc(sizeof(Tree));
    int count=0,point=0,num=0;
    while(scanf("%c",&vex[count]) != EOF){
        scanf(" %d %d\n",&left[count],&right[count]);
        count++;
    }
    p = head;
    createtree(p,1);
    myprint(head,0);
    return 0;
}