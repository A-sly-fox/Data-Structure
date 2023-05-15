#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int getStandard(int array[], int i, int j) {
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

void QuickSort(int array[], int low, int high) {
    if (low < high) {
        int standard = getStandard(array, low, high);
        QuickSort(array, low, standard - 1);
        QuickSort(array, standard + 1, high);
    }
}

int main(){
    int low,high,record[MAX],signal,count=0,low2,high2,t,mid;
    while((scanf("%d",&record[count])) != EOF)
        count++;
    QuickSort(record, 0, count - 1);
    for (int i = 0; i < count; i++)
        printf("%d ",record[i]);
    return 0;
}