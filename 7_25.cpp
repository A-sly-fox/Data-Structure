#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 30
#define MAX 100
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
int ppp = 0;
void DFS(AGraph *g,int x,int y) {
    NodeLink *p;
    visited[x]=1; 
    path[i++] = g->v[x].vertex;
    p=g->v[x].first;
    while(p){
        if(p->vindex == y)
            ppp++;
        if(!visited[p->vindex])
            DFS(g,p->vindex,y);
        p=p->next;
    }
}

void DFSGraph(AGraph *g){
    int i;
    for(i=1;i<=g->vexnum;i++)
        visited[i]=0;
    for(i=1;i<=g->vexnum;i++)
        DFS(g,i,i);
} 

int main(){
    AGraph *g;
    g = (AGraph *)malloc(sizeof(AGraph));
    NodeLink *p, *q, *r;
    char c=' ';
    int a,b,sign=0,i=0,vex,s[MAX],fst[MAX_VERTEX_NUM],lst[MAX_VERTEX_NUM];
    scanf("%d", &g->vexnum);
    for(int i = 1;i <= g->vexnum;i++){
        g->v[i].vertex = i;
        g->v[i].first = NULL;
    }
    while(c != '\n'){
        scanf("%d", &s[i++]);
        c = getchar();
    }
    for (int i = 0; i <= g->vexnum; i++)
        scanf("%d", &fst[i]);
    for (int i = 0; i <= g->vexnum; i++)
        scanf("%d", &lst[i]);
    for(int i = 1; i <= g->vexnum; i++){
        if(fst[i] > lst[i])
            continue;
        for(int j = fst[i]; j < lst[i]; j++){
            a = i;
            b = s[j];
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
        }
    }
    DFSGraph(g);
    printf((ppp)?"yes":"no");
    return 0;
}