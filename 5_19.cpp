#include<stdio.h>

int main(){
    int m,n,min,sign;
    scanf("%d %d\n",&m,&n);
    int matrix[m][n];
    for(int i=0;i<m*n;i++){
        scanf("%d",&matrix[i/n][i%n]);
    }
    for(int i=0;i<m;i++){
        min=matrix[i][0];
        for(int j=1;j<n;j++)
            if(matrix[i][j]<min)
                min=matrix[i][j];
        for(int j=0;j<n;j++)
            if(min==matrix[i][j]){
                sign=1;
                for(int k=0;k<m;k++){
                    if(min<matrix[k][j]){
                        sign=0;
                        break;
                    } 
                }
                if(sign)
                    printf("%d ",min);
            }
    }
    return 0;
}