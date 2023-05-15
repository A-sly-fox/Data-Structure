#include<stdio.h>
#define MAX 10000
int t[MAX];
int left[MAX];
int right[MAX];

int main(){
    char c=' ';
    int u,v,num=0,sign=0;
    while(c!='\n'){
        scanf("%d",&t[num++]);
        c=getchar();
    }
    for(int i=0;i<num;i++){
        scanf("%d ",&left[i]);
    }
    for(int i=0;i<num;i++){
        scanf("%d ",&right[i]);
    }
    scanf("%d %d",&u,&v);
    while(t[u]!=0){
        if(t[u]==v){
            sign++;
            break;
        }else{
            u=t[u];
        }
    }
    printf((sign)?"1":"0");
    return 0;
}