#include<stdio.h>
#include<string.h>
#define MAX 100
char s[MAX];
char t[MAX];
char v[MAX];
char result[MAX];

int main(){
    char c;
    int i=0,j,slen,tlen,vlen;
    while((c=getchar())!=' ')
        s[i++]=c;
    i=0;
    while((c=getchar())!=' ')
        t[i++]=c;
    i=0;
    while((c=getchar())!='\n')
        v[i++]=c;
    slen=strlen(s);
    tlen=strlen(t);
    vlen=strlen(v);
    for(i=0;i<slen;i++){
        for(j=0;j<tlen;j++){
            if(s[i+j]!=t[j])
                break;
        }
        if(j==tlen)
            break;
    }
    for(j=0;j<i;j++){
        result[j]=s[j];
    }
    if(i!=slen){
        for(j=0;j<vlen;j++){
            result[i+j]=v[j];
        }
        for(j=0;j<slen-(i+tlen);j++){
            result[i+vlen+j]=s[i+tlen+j];
        }
    }
    printf("%s\n",result);
    return 0;
}