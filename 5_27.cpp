#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct cross_list{
	int x;//行
	int y;//列
	int data;
	struct cross_list* right;
	struct cross_list* down;
} cross;

cross* rhead[10];
cross* chead[10];

void create(int i, int j, int number)
{
	cross *p,*q;
	q = (cross*)malloc(sizeof(cross));

	q->x = i;
	q->y = j;
	q->data = number;
	q->right = NULL;
	q->down = NULL;
	p = rhead[i];
    if(!p)
        rhead[i] = q;
    else{
        while (p->right != NULL)
            p = p->right;
        p->right = q;
    }
	p = chead[j];
    if(!p)
        chead[j] = q;
    else{
        while (p->down != NULL)
            p = p->down;
        p->down = q;
    }
}


int v1[MAX];
int v2[MAX];
int v3[MAX];

int main(){
    int m,n,i=0,j,num1,num2,sum,count1,count2;
    cross *pp;
    num1=num2=0;
    char d=' ';
    scanf("%d %d",&m,&n);
    int a[m][n];
    int b[m][n];
    int c[m][n];
    //读取数据部分，复杂度为O（t+m*n），t为稀疏矩阵的项数
    while(d!='\n'){
        scanf("%d",&v1[i++]);
        d=getchar();
    }
    for(j=0;j<m*n;j++){
        scanf("%d",&a[j/n][j%n]);
    }
    i=0;
    d=' ';
    while(d!='\n'){
        scanf("%d",&v2[i++]);
        d=getchar();
    }
    for(j=0;j<m*n;j++){
        scanf("%d",&b[j/n][j%n]);
    }
    i=0;
    //求和部分，复杂度为O（m*n）
    count1 = count2 = 0;
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			if ((a[i][j] == 0) && (b[i][j] != 0)){
				create(i, j, v2[count2]);
                count2++;
			}
			if ((a[i][j] != 0) && (b[i][j] == 0)){				
				create(i, j, v1[count1]);
                count1++;
			}
			if ((a[i][j] != 0) && (b[i][j] != 0)){
				if ((v1[count1] + v2[count2]) != 0)
					create(i, j, v1[count1] + v2[count2]);
                count1++;
				count2++;
			}
		}
	}
    for (int r = 0; r < m; r++)
        for (int s = 0; s < n; s++)
            c[r][s] = 0;
	count1 = 0;
    for (i = 0; i < m; i++){
		pp = rhead[i];
		while (pp){
			c[pp->x][pp->y] = 1;
			v3[count1++] = pp->data;
			pp = pp->right;
		}
	}
    //打印结果部分，算法复杂度为O（i+m*n），i是得到的矩阵的项数，小于t
    for(int k=0;k<count1;k++){
        printf("%d",v3[k]);
        if(k!=count1-1)
            printf(" ");
    }
    printf("\n");
    for(int k=0;k<m*n;k++){
        printf("%d",c[k/n][k%n]);
        printf(((k+1)%n)?" ":"\n");
    }
    //综上，整个算法的复杂度为O（t+m*n）
    return 0;
}