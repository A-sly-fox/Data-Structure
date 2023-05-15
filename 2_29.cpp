#include<stdio.h>
#include<stdlib.h>

int main(){
    char A[100],B[100],C[100],result[100],c=',';
    int i,j,k,sign;
    for(i=0;i<100;i++)
        A[i]=B[i]=C[i]='\0';
    i=0;
    while(c!='\n'){
        scanf("%c",&A[i]);
        c=getchar();
        i++;
    }
    i=0;
    c=',';
    while(c!='\n'){
        scanf("%c",&B[i]);
        c=getchar();
        i++;
    }
    i=0;
    c=',';
    while(c!='\n'){
        scanf("%c",&C[i]);
        c=getchar();
        i++;
    }
    i=k=0;
    while(A[i]!='\0'){
        sign=0;
        for(j=0;B[j]!='\0';j++){
            if(A[i]==B[j]){
                sign++;
                break;
            }
        }
        for(j=0;C[j]!='\0';j++){
            if(A[i]==C[j]){
                sign++;
                break;
            }
        }
        if(sign!=2){
            result[k]=A[i];
            k++;
        }
        i++;
    }
    for(i=0;i<k-1;i++)
        printf("%c,",result[i]);
    printf("%c",result[k-1]);
    return 0;
}