#include<stdio.h>
#include<string.h>
#define MAX 100
char s[MAX];
char t[MAX];

int main(){
    char c;
    int i=0;
    while((c=getchar())!=' ')
        s[i++]=c;
    i=0;
    while((c=getchar())!='\n')
        t[i++]=c;
    for(i=0;;i++){
        if(s[i]>t[i]){
            printf("1");
            break;
        }else if(s[i]<t[i]){
            printf("-1");
            break;
        }else if(s[i]==t[i] && s[i]=='\0'){
            printf("0");
            break;
        }
    }
    return 0;
}