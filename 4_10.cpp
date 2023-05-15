#include<stdio.h>
#include<string.h>
#define MAX 100
void reverse(char string[]);
char string[MAX];

int main(){
    int i=0;
    char c;
    while((c=getchar())!='\n'){
        string[i]=c;
        i++;
    }
    reverse(string);
    return 0;
}

void reverse(char string[]){
    int i=strlen(string);
    if(i==1)
        printf("%c",string[0]);
    else{
        printf("%c",string[i-1]);
        string[i-1]='\0';
        reverse(string);
    }
}