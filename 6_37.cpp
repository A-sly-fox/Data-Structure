#include<stdio.h>
#define MAX 10000
char vex[MAX];
int left[MAX];
int right[MAX];
int stack[MAX];
int sp=0;
char result[MAX];

void push(int f){
    if(sp<MAX)
        stack[sp++]=f;
    else
        printf("error:stack full, can't push %g\n",f);
}

int pop(void){
    if(sp>0)
        return stack[--sp];
    else{
        printf("error:stack empty\n");
        return 0;
    }
}

int main(){
    int count=0,point=1,num=0;
    while((vex[count]=getchar())!=EOF){
        scanf("%d %d\n",&left[count],&right[count]);
        count++;
    }
    while(point!=-1 || sp!=0){
        if(point!=-1){
            result[num++]=point;
            push(point);
            point=left[point-1];
        }else{
            point=pop();
            point=right[point-1];
        }
    }
    for(int i=0;i<num;i++){
        printf("%c ",vex[result[i]-1]);
    }
    return 0;
}