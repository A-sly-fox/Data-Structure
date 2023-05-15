#include<stdio.h>

int main(){
    double x;
    int n,i;
    int result=0;
    scanf("%lf %d",&x,&n);
    double a[n+1];
    for(i=0;i<=n;i++){
        scanf("%lf",&a[i]);
    }
    for(i=n;i>=0;i--){
        result=result*x+a[i];
    }
    printf("%d\n",result);
    return 0;
}
