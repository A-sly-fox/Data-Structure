#include<stdio.h>

int main(){
    int boy[5],girl[5],total[5],d;
    char b,c;
    for(int i=0;i<5;i++)
        boy[i]=girl[i]=total[i]=0;
    while((scanf("%c %c %c %d",&a,&b,&c,&d))!=EOF){
        if(b=='M')
            boy[c-'A']+=d;
        else if(b=='F')
            girl[c-'A']+=d;
        getchar();
    }
    for(int i=0;i<5;i++){
        total[i]=boy[i]+girl[i];
        if(boy[i]!=0)
            printf("%c M %d\n",i+'A',boy[i]);
        if(girl[i]!=0)
            printf("%c F %d\n",i+'A',girl[i]);
        if(total[i]!=0)
            printf("%c %d\n",i+'A',total[i]);
    }
    return 0;
}
