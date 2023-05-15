#include <stdio.h>
#include <stdlib.h>
#define MAX 100
static int vex;

typedef struct Node {
    char data;
    struct Node *child,*brother;
}Tree; 

typedef struct{
    int* data;
    int len;
}stack;

typedef struct{
    int child;
    int brother;
    int data;
}node;

void myprintf(node* p,int head,int vex){
    printf("%d",head);
    for(int i=1;i<=vex;i++)
        printf(" %d",p[i].child);
    printf("\n%d",head);
    for(int i=1;i<=vex;i++)
        printf(" %d",p[i].brother);
    printf("\n");
}

stack searchpreorder(node* p,int head,stack st){
    st.len++;
    st.data[st.len-1]=head;
    if(p[head].child)
        st=searchpreorder(p,p[head].child,st);
    if(p[head].brother)
        st=searchpreorder(p,p[head].brother,st);
    return st;
}

stack searchinorder(node* p, int head, stack st){
    if (p[head].child != 0)
        st = searchinorder(p, p[head].child, st);
    st.len++;
    st.data[st.len - 1] = head;
    if (p[head].brother != 0)
        st = searchinorder(p, p[head].brother, st);
    return st;
}

stack searchpostorder(node* p,int head,stack st){
    if(p[head].child!=0)
        st=searchpostorder(p,p[head].child,st);
    if(p[head].brother!=0)
        st=searchpostorder(p,p[head].brother,st);
    st.len++;
    st.data[st.len-1]=head;
    return st;
}

void preorder_traversal(node *v,int head){
    int *p,i,j;
    stack st;
    st.data=(int*)malloc(sizeof(int)*MAX);
    st.len=0;
    st=searchpreorder(v,head,st);
    p=st.data;
    for(i=1;i<=vex;i++)
        if(!v[i].child){
            for (j = 0; j < vex; j++)
                if (p[j] == i)
                    break;
            if (j < vex && j)
                v[i].child = p[j - 1];
            else
                v[i].child = 0;
        }
    myprintf(v,head,vex);
}

void inorder_traversal(node *v,int vex,int head){
    int *p,i,k;
    stack st;
    st.data=(int*)malloc(sizeof(int)*MAX);
    st.len=0;
    st=searchinorder(v,head,st);
    p=st.data;
    for(i=1;i<=vex;i++)
        if(!v[i].child){
            for (k = 0; k < vex; k++)
                if (p[k] == i)
                    break;
            if (k < vex && k != 0)
                v[i].child = p[k - 1];
            else
                v[i].child = 0;
        }
    for(i=1;i<=vex;i++){
        if(!v[i].brother){
            for (k = 0; k < vex; k++)
                if (p[k] == i)
                    break;
            if (k < vex - 1)
                v[i].brother = p[k + 1];
            else
                v[i].brother = 0;
        }
    }
    myprintf(v,head,vex);
}

void postorder_traversal(node *v,int vex,int head){
    int *p,i,k;
    stack st;
    st.data = (int*)malloc(sizeof(int) * MAX);
    st.len = 0;
    st = searchpostorder(v, head, st);
    p = st.data;
    for(i=1;i<=vex;i++)
        if(!v[i].brother){
            for (k = 0; k < vex; k++)
                if (p[k] == i)
                    break;
            if (k < vex - 1)
                v[i].brother = p[k + 1];
            else
                v[i].brother = 0;
        }
    myprintf(v,head,vex);
}

int main(){
    int len;
    node v[MAX],*v1,*v2;
    scanf("%d",&vex);
    len=1;
    while(len <= vex){
	scanf("%d %d %d",&v[len].data,&v[len].child,&v[len].brother);
        getchar();
        len++;
    }
    int head,a,b;
    stack st;
    st.data=(int*)malloc(sizeof(node)*MAX);
    st.data[0]=1;
    st.len=0;
    a = b = 1;
    while(a<=vex){
        for(; a <= b; a++){
            if(v[a].child>b) 
                b = v[a].child;
            if(v[a].brother>b) 
                b = v[a].brother;
        }
        if(a <= vex){
            st.data[++st.len] = a;
            b++;
        }
    }
    for(int i = 0; i + 1 <= st.len; i++)
        v[st.data[i]].brother=v[st.data[i+1]].data;
    head = st.data[0];
    v1 = (node*)malloc(sizeof(node)*(vex+1));
    v2 = (node*)malloc(sizeof(node)*(vex+1));
    for(int i = 1; i <= vex; i++){
        v1[i].data = v2[i].data = v[i].data;
        v1[i].child = v2[i].child = v[i].child;
        v1[i].brother = v2[i].brother = v[i].brother;
    }
    preorder_traversal(v,head);
    inorder_traversal(v1,vex,head);
    postorder_traversal(v2,vex,head);
    return 0;
}