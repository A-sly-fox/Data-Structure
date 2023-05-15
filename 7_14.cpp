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

int main(){
    AGraph *g;
    g = (AGraph *)malloc(sizeof(AGraph));
    NodeLink *p, *q, *r;
    char c;
    int a,b,sign=0;
    scanf("%d,%d",&g->vexnum,&g->edgenum);
    for(int i = 0;i <= g->vexnum;i++){
        g->v[i].vertex = i;
        g->v[i].first = NULL;
    }
    for (int i = 0; i < g->edgenum; i++){
        scanf("%d-%d", &a, &b);
        if(a == g->vexnum || b == g->vexnum){
            sign = 1;
        }
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
        getchar();
    }
    for(int i = sign;i < g->vexnum + sign;i++){
        printf("%d",g->v[i].vertex);
        p=g->v[i].first;
        while(p) {
            if(p == g->v[i].first)
                printf(" %d",p->vindex);
            else
                printf(",%d",p->vindex);
            p=p->next;
        }
        printf("\n");
    }
    return 0;
}