#include<stdio.h>
#define MAX 10000
char vex[MAX];
int left[MAX];
int right[MAX];
int queue[MAX];

int main(){
    int count=0,high=1,low=0,point=1,num=0;
    while((vex[count]=getchar())!=EOF){
        scanf("%d %d\n",&left[count],&right[count]);
        count++;
    }
    queue[0]=point;
    while(count>num){
        if(queue[low]!=-1){
            num++;
            queue[high++]=left[queue[low]-1];
            queue[high++]=right[queue[low]-1];
        }else{
            queue[high++]=-1;
            queue[high++]=-1;
        }
        low++;
    }
    int sign=0;
    for(int i=0;i<high;i++){
        if((queue[i]+sign)==-1)
            sign++;
        else if(sign==1 && queue[i]!=-1)
            sign++;
    }
    printf((sign>1)?"No":"Yes");
    return 0;
}