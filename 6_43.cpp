#include<stdio.h>
#define MAX 100
int L[MAX];
int R[MAX];
int vertex[2*MAX];
int vertex2[2*MAX];
int begin=0,end=1;

void createvertex2(int i){
    if(begin==end);
    else{
        int t,j;
        for(t=0;t<MAX;t++)
            if(i==vertex[t])
                break;
        t++;
        if(R[t])
            vertex2[end++]=R[t];
        if(L[t])
            vertex2[end++]=L[t];
        createvertex2(vertex2[++begin]);
    }
}

int main(){
    char c=' ';
    int v=1,l,r,k;
    for(l=0;l<MAX;l++){
        scanf("%d",&L[l]);
        c=getchar();
        if(c=='\n')
            break;
    }
    for(r=0;r<MAX;r++){
        scanf("%d",&R[r]);
        c=getchar();
        if(c=='\n')
            break;
    }
    vertex[0]=L[0];
    for(int i=1;i<MAX;i++){
        if(L[i])
            vertex[v++]=L[i];
        if(R[i])
            vertex[v++]=L[i];
    }
    vertex2[0]=L[0];
    createvertex2(vertex2[0]);
    printf("%d ",L[0]);
    for(int i=1;i<=l;i++){
        printf("%d",R[i]);
        printf((i==l)?"\n":" ");
    }
    printf("%d ",L[0]);
    for(int i=1;i<=r;i++){
        printf("%d",L[i]);
        printf((i==r)?"\n":" ");
    }
    return 0;
}