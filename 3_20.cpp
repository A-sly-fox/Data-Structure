#include<stdio.h>
#define MAX 100
int pic[MAX][MAX];

void substitution(int abscissa,int ordinate,int x,int y){
    if(pic[abscissa][ordinate] == 1){
        pic[abscissa][ordinate] = 2;
    }else
        return;
	if (abscissa != 0)
		substitution(abscissa - 1, ordinate, x, y);
	if (abscissa != x)
		substitution(abscissa + 1, ordinate, x, y);
	if (ordinate != 0)
        substitution(abscissa, ordinate - 1, x, y);
	if (ordinate != y)
		substitution(abscissa, ordinate + 1, x, y);
}

int main(){
	int x,y,a,b,c;
	int number;
	scanf("%d %d %d %d %d",&x,&y,&a,&b,&c);
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
            scanf("%d", &number);
            pic[i][j] = number;
		}
	}
	if (pic[a][b] == 1)
		substitution(a,b,x,y);
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++){
			printf("%d", pic[i][j]);
			if (j == y -1)
				printf("\n");
		}
	return 0;
}