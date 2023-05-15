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
        int MPL;
        NodeLink *first;
    } v[MAX_VERTEX_NUM];
} AGraph;

int visited[MAX_VERTEX_NUM];

void BFS(AGraph *g,int x) {
    // 用一个数组q作辅助队列, q[0..front)存放的是访问过的顶点, 
    // q[front..rear)存放的是已访问顶点的相邻点，是马上要访问的顶点
    int q[MAX_VERTEX_NUM],path[MAX_VERTEX_NUM],front,rear,i;
    for (int i = 1; i <= MAX_VERTEX_NUM; i++)
    {
        path[i] = 0;
    }
    
    NodeLink *p;
    front=rear=0; q[rear++]=x;
    while(front != rear) //队列非空
    { //顶点出队列，并访问它
        x=q[front++]; visited[x]=1;
        p=g->v[x].first;
        while(p!=NULL) {
            for(i=0;i<rear;i++) //判邻接点是否在数组q中
                if(p->vindex == q[i])
                    break;
            if(i >=rear)//邻接点未被访问且不在队列中，则入队列
                q[rear++]=p->vindex;
            p=p->next; // 找x的下一个邻接点
        }
    }
}


void BFSGraph(AGraph *g){
    int i;
    for(i=1;i<=g->vexnum;i++)
        visited[i]=0;
    for(i=1;i<=g->vexnum;i++)
        if(!visited[i])
            BFS(g,i);
}


int main(){
    AGraph *g;
    g = (AGraph *)malloc(sizeof(AGraph));
    NodeLink *p, *q, *r;
    char c=',';
    int a,b,sign;
    scanf("%d", &g->vexnum);
    for(int i = 1;i <= g->vexnum;i++){
        g->v[i].vertex = i;
        g->v[i].first = NULL;
        g->v[i].MPL = 0;
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
    BFSGraph(g);
    //printf("%d\n",g->vexnum);
    /*for (int i = 1; i <= g->vexnum; i++){
        DFSGraph(g,i);
    }
    for (int i = 1; i <= g->vexnum; i++)
    {
        printf("%d ",g->v[i].MPL);
    }*/
    
    
    /*for(int i = 1;i < g->vexnum + 1;i++){
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
    }*/
    return 0;
}