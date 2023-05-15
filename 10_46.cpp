#include<stdio.h>
#define MAXSIZE 100
#define MAXINT 0x7fffffff

typedef struct {
    int rc;
    int next;
} SLNode;

typedef struct {
    SLNode  r[MAXSIZE+1];
    int length;
}SLinkListType;

int main(){
    SLinkListType SL;
    int length,count=0,a;
    scanf("%d",&length);
    while((scanf("%d",&SL.r[count+1].rc)) != EOF)
        count++;
    SL.length = length;
    int i, j, k;
    SL.r[0].rc = MAXINT;
    SL.r[0].next =1;
    SL.r[1].next = 0;
    for (i=2; i<=SL.length; ++i ){
        for (j=0, k = SL.r[0].next;SL.r[k].rc <= SL.r[i].rc; j=k, k=SL.r[k].next )
            ;
        SL.r[j].next = i;
        SL.r[i].next = k; 
  	}
    a = SL.r[0].next;
    for (int  j = 0; j < length; j++){
        printf("%d",SL.r[a].rc);
        if(j != length-1)
            printf(" ");
        a = SL.r[a].next;
    }
    return 0;
}