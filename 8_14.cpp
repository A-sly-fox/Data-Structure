#include<stdio.h>
#define MAX 100

int getStandard(int *array, int i, int j) {
    int key = array[i];
    while (i < j) {
        while (i < j && array[j] >= key)
            j--;
        if (i < j) 
            array[i] = array[j];
        while (i < j && array[i] <= key)
            i++;
        if (i < j)
            array[j] = array[i];
    }
    array[i] = key;
    return i;
}

void QuickSort(int *array, int low, int high) {
    if (low < high) {
        int standard = getStandard(array, low, high);
        QuickSort(array, low, standard - 1);
        QuickSort(array, standard + 1, high);
    }
}

int main(){
	char c;
	int line, count,input[MAX][MAX],output[MAX][MAX],next_k[MAX],current_k[MAX],num = 0,max = 0,exp,row,line2;

	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			input[i][j] = -1;
			output[i][j] = -1;
		}
		current_k[i] = -1;
		next_k[i] = -1;
	}
	for (line = 0; line < MAX; line++){
		c = getchar();
		if (c == '\n')
            break;
        else{
			input[line][0] = c - '0';
			getchar();
			for (int j = 1; j < MAX; j++){
				scanf("%d", &input[line][j]);
				c = getchar();
				if (c == '\n')
					break;
			}
		}
	}
	for (;; line++){
		c = getchar();
		if (c == '\n' || c == EOF)
            break;
        else{
			input[line][0] = c - '0';
			scanf(" %d", &input[line][1]);
			getchar();
		}
	}
	for (int i = 0; input[i][0] != -1; i++)
		if (input[i][0] > max)
			max = input[i][0];
	line2 = 0;
	for (int i = 0; i < MAX; i++){
		count = 0;
		for (int j = 0; input[j][0] != -1; j++){
			if (input[j][0] == i){
				for (int k = 1; input[j][k] != -1; k++){
					current_k[count] = input[j][k];
					count++;
				}
			}
		}
		if (num > 0)
			for (int j = 0; j < num; j++)
				current_k[count++] = next_k[j];
		num = 0;
		QuickSort(current_k, 0, count - 1);
		exp = 1;
		for (int j = 0; j < i; j++)
			exp = exp * 2;
		for (int j = 0; j < count; j++){
			for (int k = j + 1; k < count; k++){
				if (j != k && current_k[k] == current_k[j] + exp && !(current_k[j] % (exp * 2))){
					next_k[num++] = current_k[j];
					current_k[j] = -1;
					current_k[k] = -1;
				}
			}
		}
		row = 0;
		for (int j = 0; j < count; j++){
			if (current_k[j] != -1)
				output[line2][row++ + 1] = current_k[j];
		}
		if (row > 0)
			output[line2++][0] = i;
		if (!count && i > max + 1)
			break;
	}
	for (int i = 0; i < line2; i++){
		for (int j = 0; output[i][j] != -1; j++){
			printf((j == 0)?"":" ");
			printf("%d", output[i][j]);
		}
		printf("\n");
	}
	return 0;
}