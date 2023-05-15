#include<stdio.h>
#define MAX 100000

int a[MAX];
int b[MAX];

int main(){
    char c = ' ';
    int i,j,x,y;
    i = j = 0;
    while(c!='\n'){
        scanf("%d",&a[i++]);
        c = getchar();
    }
    c = ' ';
    while(c!='\n'){
        scanf("%d",&b[j++]);
        c = getchar();
    }
    x = y = 0;
    while(x < i && y < j){
        if(a[x] < b[y]){
            printf("%d ",a[x]);
            x++;
        }else{
            printf("%d ",b[y]);
            y++;
        }
    }
    for(int s = x; s < i; s++){
        printf("%d ",a[s]);
    }
    for(int s = y; s < j; s++){
        printf("%d ",b[s]);
    }
    return 0;
}