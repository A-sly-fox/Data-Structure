#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 30
typedef struct node {
    int vindex;
    struct node *next;
} NodeLink;

typedef struct {
    int vexnum,edgenum; 
    struct {
        int vertex;
        NodeLink *first;
    } v[MAX_VERTEX_NUM];
} AGraph;

int visited[MAX_VERTEX_NUM];
int path[MAX_VERTEX_NUM];
int i=0; 
void DFS(AGraph *g,int x) {
    NodeLink *p;
    visited[x]=1; 
    path[i++] = g->v[x].vertex;
    p=g->v[x].first;
    while(p){
        if(!visited[p->vindex])
            DFS(g,p->vindex);
        p=p->next; 
    }
}

void DFSGraph(AGraph *g,int a){
    int i;
    for(i=0;i<g->vexnum;i++)     
        visited[i]=0;
    if(!visited[a])
        DFS(g,a);
} 

int main(){
    AGraph *g;
    g = (AGraph *)malloc(sizeof(AGraph));
    NodeLink *p, *q, *r;
    char c=',';
    int a,b,sign=0,vex;
    scanf("%d", &g->vexnum);
    for(int i = 1;i <= g->vexnum;i++){
        g->v[i].vertex = i;
        g->v[i].first = NULL;
    }
    while(c != '\n'){
        scanf("%d-%d", &a, &b);
        p = (NodeLink *)malloc(sizeof(NodeLink));
        p->vindex = b;
        if(g->v[a].first == NULL){
            g->v[a].first = p;
            p->next =NULL;
        }else{
            q = g->v[a].first;
            if(q->vindex < p->vindex){
                g->v[a].first = p;
                p->next = q;
            }else{
                r = q->next;
                while(q != NULL){
                    if(r == NULL){
                        p->next = r;
                        q->next = p;
                        break;
                    }else if (r->vindex < b){
                        p->next = r;
                        q->next = p;
                        break;
                    }else{
                        q = q->next;
                        r = r->next;
                    }
                }
            }
            
        }
        c=getchar();
    }
    scanf("%d,%d", &a, &b);
    DFSGraph(g,a);
    for(int i = 0; i < MAX_VERTEX_NUM; i++){
        if(path[i] == b){
            printf("yes");
            return 0;
        }
    }
    printf("no");
    return 0;
}