#include<stdio.h>
#include<string.h>
#define MAX 10000
char first[MAX];
char mid[MAX];

void change(char *a,char *b,int len){
    if(!len)
        return;
    char c=a[0];
    char left1[MAX],right1[MAX],left2[MAX],right2[MAX];
    int location=0;
    while(b[location]!=c){
        location++;
    }
    for(int i=0;i<location;i++){
        left2[i]=b[i];
        left1[i]=a[1+i];
    }
    for(int i=0;i<len-location-1;i++){
        right2[i]=b[i+location+1];
        right1[i]=a[i+location+1];
    }
    change(left1,left2,location);
    change(right1,right2,len-location-1);
    printf("%c",a[0]);
}

int main(){
    char c;
    int num=0;
    while((c=getchar())!='\n'){
        first[num++]=c;
    }
    first[num]='\0';
    for(int i=0;i<num;i++)
        mid[i]=getchar();
    mid[num]='\0';
    change(first,mid,num);
    return 0;
}