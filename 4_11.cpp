#include<stdio.h>
#include<string.h>
#define MAX 100
char s[MAX];
char t[MAX];
char r[MAX];
int location[MAX];

int main(){
    char c;
    int i=0,j,length1,length2,length3=0;
    while((c=getchar())!=' ')
        s[i++]=c;
    i=0;
    while((c=getchar())!='\n')
        t[i++]=c;
    length1=strlen(s);
    length2=strlen(t);
    for(i=0;i<length2;i++)
        for(j=0;j<length1;j++)
            if(s[j]==t[i])
                s[j]='#';
    for(i=0;i<length1;i++){
        if(s[i]=='#'){
            ;
        }else{
            for(j=0;j<length3;j++){
                if(s[i]==r[j])
                    break;
            }
            if(j<length3){
                continue;
            }else{
                r[length3]=s[i];
                location[length3]=i;
                length3++;
            }
        }
    }
    if(length3==0){
        printf("-1");
    }else{
        printf("%s ",r);
        for(i=0;i<length3;i++)
            printf("%d",location[i]);
    }
    return 0;
}