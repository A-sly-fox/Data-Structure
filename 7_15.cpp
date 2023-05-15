#include<stdio.h>
#include<stdlib.h>
#define Max 30
typedef struct{
    int vexnum,arcnum;
    char vexs[Max];
    int A[Max][Max];
} MGraph;

int main(){
    int vex,sign,a,b;
    MGraph *g;
    char c[2];
    g = (MGraph *)malloc(sizeof(MGraph));
    scanf("%d", &vex);
    for (int i = 0; i < Max; i++){
        for (int j = 0; j < Max; j++){
            if(i<vex && j<vex)
                scanf("%d", &g->A[i][j]);
            else
                g->A[i][j] = -1;
        } 
    }
    while((scanf("%s",c)) != EOF){
        if(c[0] == 'D'){
            if(c[1] == 'A')
                sign = 3;//DA
            else
                sign = 2;//DV
        }else{
            if(c[1] == 'A')
                sign = 1;//IA
            else
                sign = 0;//IV
        }
        switch (sign){
            case 0:
                scanf("%d", &a);
                if(a != vex -1){
                    for(int i = vex; i > a; i--)
                        for(int j = 0; j< Max; j++)
                            g->A[i][j] = g->A[i-1][j];
                    for(int j = vex; j > a; j--)
                        for(int i = 0; i< Max; i++)
                            g->A[i][j] = g->A[i][j-1];
                }
                vex++;
                for(int i = 0; i < vex; i++){
                    g->A[i][a] = 0;
                    g->A[a][i] = 0;
                }
                break;

            case 1:
                scanf("%d %d", &a, &b);
                g->A[a][b] = 1;
                g->A[b][a] = 1;
                break;

            case 2:
                scanf("%d", &a);
                vex--;
                for(int i = 0;i < Max; i++){
                    g->A[a][i] = -1;
                    g->A[i][a] = -1;
                }
                break;

            case 3:
                scanf("%d %d", &a, &b);
                g->A[a][b] = 0;
                g->A[b][a] = 0;
                break;

            default:
                break;
        }
    }
    int count;
    for (int i = 0; i < Max; i++)
    {
        count = 0;
        for (int  j = 0; j < Max; j++)
        {
            if(g->A[i][j] != -1){
                printf("%d", g->A[i][j]);
                count++;
                if(count != vex)
                    printf(" ");
            }
        }
        if(count)
            printf("\n");
    }
    return 0;
}