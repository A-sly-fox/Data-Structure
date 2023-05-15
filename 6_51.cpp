#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node* lchild;
	struct node* rchild;
	struct node* parent;
	char data;
} Node;

Node* createtree(){
	Node* p;
	char c;
	c = getchar();
	if (c == '\n' || c == '#')
		return NULL;
	p = (Node*)malloc(sizeof(Node));
	p->data = c;
	p->lchild = createtree();
	p->rchild = createtree();
	return p;
}

void parent(Node* head){
	Node* p;
	if (head->lchild){
		p = head->lchild;
		p->parent = head;
		parent(p);
	}
	if (head->rchild){
		p = head->rchild;
		p->parent = head;
		parent(p);
	}
}

int brackets(Node* head){
	int i = 0;
	if (!head->parent)
		return i;
	char c = head->data;
	char d = head->parent->data;
	if ((c == '+' || c == '-') && (d == '*' || d == '/'))
		i++;
	else if((head->parent->rchild == head) && (((c == '+' || c == '-') && d == '-') || ((c == '*' || c == '/') && d == '/')))
		i++;
	return i;
}

void myprint(Node* head){
	int x;
	x = brackets(head);
	if(x)
		printf("(");
	if(head->lchild)
		myprint(head->lchild);
	printf("%c", head->data);
	if(head->rchild)
		myprint(head->rchild);
	x = brackets(head);
	if(x)
		printf(")");
}

int main(){
	Node* head;
	head = createtree();
	head->parent = NULL;
	parent(head);
	myprint(head);
	return 0;
}