#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    char s[MAX],sub[MAX];
    int i,j,k,length,sublength,location,max;
    for(i=0;i<MAX;i++){
        s[i]=sub[i]=0;
    }
    scanf("%s",s);
    length=strlen(s);
    location=max=-1;
    for(i=0;i<length;i++){
        for(sublength=1;sublength<length;sublength++){
            for(j=i+1;j<length;j++){
                for(k=0;k<sublength;k++){
                    if(s[i+k]!=s[j+k]){
                        break;
                    }
                }
                if(k==sublength){
                    if(sublength>max){
                        max=sublength;
                        location=i;
                    }
                    j=length+1;
                    break;
                }
            }
            if(j!=length+1)
                break;
        }
    }
    for(i=0;i<max;i++)
        printf("%c",s[location+i]);
    printf((location==-1)?"":" ");
    printf("%d",location);
    return 0;
}