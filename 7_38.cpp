#include<stdio.h>
#include<stdlib.h>
#define MAX_VER_NUM 30

typedef struct node{
	char data;
	struct node* next;
} NodeLink;
NodeLink* v[MAX_VER_NUM];

void insert(int d, char c){
	NodeLink* p,* q;
    q = (NodeLink*)malloc(sizeof(NodeLink));
	p = v[d];
	while (p->next)
		p = p->next;
    q->data = c;
    q->next = NULL;
    p->next = q;
}

void DFS(int b){
	NodeLink *p,*q;
    char c;
	p = v[b]->next;
	q = p;
    c = p->data;
	if (c == '+' || c == '-' || c == '*' || c == '/'){
		p = p->next;
		DFS(p->data - '0');
		p = p->next;
		DFS(p->data - '0');
	}
	printf("%c", q->data);
    return;
}

int main(){
	int vex;
	char c, d, e;
	NodeLink* p;
	scanf("%d\n", &vex);
	for (int i = 0; i < vex; i++){
		p = (NodeLink*)malloc(sizeof(NodeLink));
        p->data = i;
        p->next = NULL;
        v[i] = p;
	}
	for (int i = 0; i < vex; i++){
		e = getchar();
        insert(i, e);
		if (e == '+' || e == '-' || e == '*' || e == '/'){
			scanf(" %c %c\n", &c, &d);
			insert(i, d);
			insert(i, c);
		}else
			getchar();
	}
	DFS(0);
	return 0;
}