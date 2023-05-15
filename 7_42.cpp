#include<stdio.h>
#include<stdlib.h>
#define MAX_VER_NUM 30
#define MAX 100

typedef struct node{
	int data;
	int weight;
	struct node* next;
} Node;
Node* v[MAX_VER_NUM];

int path_length[MAX];
int path = 0;
int visit[MAX];

void insert(int num, int data, int weight){
	Node *p,*q;
    q = (Node*)malloc(sizeof(Node));
	p = v[num - 1];
	while (p->next != NULL)
		p = p->next;
    q->data = data;
    q->weight = weight;
    q->next = NULL;
    p->next = q;
}

void DFS(int a, int b, int num, int weight){
	Node* p = v[a - 1];
	for (int i = 0; i < num - 1; i++)
		if (visit[i] == p->data)
			return;
	if (p->data == b){
		path_length[path] = weight;
		path++;
		return;
	}
	visit[num - 1] = a;
	if (p){
		while (p->next){
			p = p->next;
			DFS(p->data, b, num + 1, weight + p->weight);
		}
	}
}

int main(){
	int vex,a,count = 0,begin[MAX],end[MAX],weight[MAX],length,num = 0;
    char c;
    Node* p;
	for (int i = 0; i < MAX; i++)
		end[i] = begin[i] = weight[i] = path_length[i] = visit[i] = -1;
	scanf("%d %d\n", &vex, &a);
	for (int i = 0; i < vex; i++){
		p = (Node*)malloc(sizeof(Node));
		if (p){
			p->data = i + 1;
			p->next = NULL;
			p->weight = 0;
			v[i] = p;
		}
	}
	for (int i = 0; i < MAX; i++){
		c = getchar();
		if (c == '\n' || c == EOF)
			break;
		else{
			end[i] = c - '0';
			getchar();
			scanf("%d %d", &begin[i], &weight[i]);
			count++;
			getchar();
		}
	}
	for (int i = 0; i < vex; i++)
		for (int j = 0; j < count; j++)
			if (end[j] == i + 1)
				insert(i + 1, begin[j], weight[j]);
	for (int i = 0; i < vex; i++){
		length = 0x7fffffff;
		path = 0;
		if (i + 1 != a){
			DFS(a, i + 1, 1, 0);
			for (int j = 0; j < path; j++)
				if (path_length[j] < length)
					length = path_length[j];
            printf("%d", length);
            printf((num == vex - 2)?"\n":",");
			num++;
		}
	}
	return 0;
}