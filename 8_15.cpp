#include<stdio.h>
#define MAX 100

int main(){
    int j,low,high,p,num,count = 0,state[MAX];
	scanf("%d %d %d", &low, &high, &p);
	num = (high - low) / p;
	for (int i = 0; i < num; i++){
		scanf("%d", &state[i]);
        if (state[i] == 0)
			count++;
    }
	if (count == 0){
		printf("0 0 0\n");
		return 0;
	}else if (count == num){
		printf("0 %d %d\n", low, high - low);
		return 0;
	}
	for (int i = 0; i < num; i++){
		count = 0;
		for (j = i; j < num; j++){
			if (!state[j])
				count++;
			else{
				if (count)
					printf("0 %d %d\n", low + i * p, p * count);
				break;
			}
		}
		i = j;
	}
	return 0;
}