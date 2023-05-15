#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* wait = (int*)malloc(sizeof(int) * numsSize);
    int temp;
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++){
        temp = nums[i];
        for(int j = 0; j < i; j++){
            if(wait[j] == temp){
                int* ret = (int*)malloc(sizeof(int) * 2);
                ret[0] = j;
                ret[1] = i;
                return ret;
            }
        }
        wait[i] = target - nums[i];
    }
}

int main(){
    int a = 123;
    printf("%d\n", a);
    fmax(1.0,2.0);
    return 0;
}
