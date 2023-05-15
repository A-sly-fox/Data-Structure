#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int sp = 0;

void push(int f){
    if(sp<MAX)
        stack[sp++]=f;
}

int pop(void){
    if(sp>0)
        return stack[--sp];
    return 0;
}

void sort3(int *record,int low,int high){
    int a,b,c,e,d,f;
    a = record[low];
    b = record[low+1];
    c = record[low+2];
    if(a>b){
        if(c>a){
            d=c;
            e=a;
            f=b;
        }else if(c<b){
            d=a;
            e=b;
            f=c;
        }else{
            d=a;
            e=c;
            f=b;
        }
    }else{
        if(c>b){
            d=c;
            e=b;
            f=a;
        }else if(c<a){
            d=b;
            e=a;
            f=c;
        }else{
            d=b;
            e=c;
            f=a;
        }
    }
    record[low] = f;
    record[low+1] = e;
    record[low+2] = d;
}

int main(){
    int low,high,record[MAX],signal,count=0,low2,high2,t,mid;
    while((scanf("%d",&record[count])) != EOF)
        count++;
    push(0);
    push(count);
    low = 0;
    high = count;
    while(1){
        if(low == high-1){
            if(!sp)
                break;
            high = pop();
            low = pop();
        }else if(low == high-2){
            if(record[low] > record[low+1]){
                t = record[low];
                record[low] =record[low+1];
                record[low+1] = t;
            }
            if(!sp)
                break;
            high = pop();
            low = pop();
        }else if(low == high-3){
            sort3(record,low,high);
            if(!sp)
                break;
            high = pop();
            low = pop();
        }else{
            signal = record[low];
            low2 = low;
            high2 = high - 1;
            while (low2 < high2) {
                while (low2 < high2 && record[high2] >= signal)
                            --high2;
                record[low2] = record[high2];
                while (low2 < high2 && record[low2] <= signal) 
                            ++low2;
                record[high2]=record[low2];
            }
            record[low2] = signal;
            mid = (low + high)/2;
            if(low2 < mid){
                pop();
                pop();
                push(low2+1);
                push(high);
                high = low2;
            }else{
                pop();
                pop();
                push(low);
                push(low2);
                low = low2+1;
            }
        }
    }
    for (int i = 0; i < count; i++){
        printf("%d ",record[i]);
    }
    return 0;
}