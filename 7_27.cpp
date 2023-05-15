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
static int signal = 0;
void DFS(AGraph *g,int x,int y,int z){
    NodeLink *p;
    visited[x]=1;
    p=g->v[x].first;
    while(p){
        if(p->vindex == y && z==1){
            signal++;
        }  
        if(!visited[p->vindex])
            DFS(g,p->vindex,y,z-1);
        p=p->next;
    }
}

void DFSGraph(AGraph *g,int a,int b,int k){
    int i;
    for(i=0;i<g->vexnum;i++)     
        visited[i]=0;
    DFS(g,a,b,k);
} 

int main(){
    AGraph *g;
    g = (AGraph *)malloc(sizeof(AGraph));
    NodeLink *p, *q, *r;
    char c=',';
    int a,b,sign,vex,length,aa,bb;
    scanf("%d,%d", &g->vexnum, &length);
    scanf("%d,%d", &aa, &bb);
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
    DFSGraph(g,aa,bb,length);
    printf((signal)?"yes":"no");
    return 0;
}