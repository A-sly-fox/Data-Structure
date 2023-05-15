#include<stdio.h>
#define max 100
char store[max];
char path1[max];
char path2[max];

void path(char *a,char *b,char c){
    int location=0,i=0;
    while(a[i]!=c){
        if(a[i]!='^'){
            b[location++]=a[i++];
        }else{
            while(b[location-1]==' ')
                location-=2;
            b[location++]=' ';
            i++;
        }
    }
    b[location++]=c;
    b[location]='\0';
}

int main(){
    char c,a,b,d;
    int i=0;
    while((c=getchar())!='\n')
        store[i++]=c;
    store[i]='\0';
    d=store[0];
    scanf("%c %c",&a,&b);
    path(store,path1,a);
    path(store,path2,b);
    i=0;
    while((c=path1[i++])!='\0'){
        if(c==' ')
            continue;
        for(int j=0;;j++){
            if(path2[j]=='\0')
                break;
            else if(c==path2[j] && c!=a && c!=b && c!=store[0]){
                d=c;
                break;
            }
        }
    }
    printf("%c",d);
    return 0;
}