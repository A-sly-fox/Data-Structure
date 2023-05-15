#include<stdio.h>
#include<string.h>

int main(){
    char a[100],b[100],c;
    int i,j,k;
    for(i=0;i<100;i++)
        a[i]=b[i]='\0';
    i=j=k=0;
    while((c=getchar())!='\n'){
        if(c!=','){ 
            a[i]=c;
        	i++;
        } 
    }
    while((c=getchar())!='\n'){
        if(c!=','){ 
            b[j]=c;
        	j++;
        } 
    }
    k=strcmp(a,b);
    if(k<0){
        printf("1");
    }else if(k>0){
        printf("2");
    }else{
        printf("0");
    }
    return 0;
}
