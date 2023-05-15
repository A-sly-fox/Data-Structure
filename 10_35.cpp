#include<stdio.h>

int data[100];
int parent = 0;
int count = 0;

void createtree(int i, int parent){
	int j;
	if (!i)
		return;
	j = (i - 1) / 2;
	if (parent > data[j]){
		data[i] = data[j];
		data[j] = parent;
		createtree(j, parent);
	}
	return;
}

void exchange(int *data, int x,int y){
    int t;
    t = data[x];
    data[x] = data[y];
    data[y] = t;
}

int main(){
	int i , j;
	char c = ' ';
	while(c != '\n'){
		scanf("%d", &data[count++]);
		c = getchar();
	}
	for (j = 0; j < count; j++){
		for (i = 1; i < (count - j); i++){
			parent = data[i];
			createtree(i, parent);
		}
        exchange(data,0,count - 1 - j);
	}
	for (i = 0; i < count; i++)
		printf("%d ", data[i]);
    return 0;
}