#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define OPSETSIZE 7 
char OPSET[OPSETSIZE]={'+' , '-' , '*' , '/' ,'(' , ')' , '#'}; 
unsigned char Prior[OPSETSIZE][OPSETSIZE] = { 
 ' ',' ','<','<','<','>','>',
 ' ',' ','<','<','<','>','>',
 '>','>',' ',' ','<','>','>',
 '>','>',' ',' ','<','>','>',
 '<','<','<','<','<','=',' ',
 '>','>','>','>',' ','>','>', 
'<','<','<','<','<',' ','=' };

int opset(char a){
    for (int i=0; i< OPSETSIZE; i++)
        if (a == OPSET[i]) 
	        return i;
    return -1;
}

char stack1[MAX];
char stack2[MAX];
int sp1 = 0;
int sp2 = 0;

void push1(char f){
    if(sp1<MAX)
        stack1[sp1++]=f;
}

void push2(char f){
    if(sp2<MAX)
        stack1[sp2++]=f;
}

char pop1(void){
    if(sp1>0)
        return stack1[--sp1];
    return 0;
}

char pop2(void){
    if(sp2>0)
        return stack1[--sp2];
    return 0;
}

int main(){
    char c,a,b;
    push2('#');
    while((c = getchar())!= '\n'){
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
           printf("%c",c);
        }else if(opset(c)>=0 && opset(c)<=3){
            b = pop2();
            a = Prior[opset(c)][opset(b)];
            if(a == '>' || b == '('){
                push2(b);
                push2(c);
            }else{
                while(a != '>'){
                    printf("%c",b);
                    b = pop2();
                    a = Prior[opset(c)][opset(b)];
                }
                push2(b);
                push2(c);
            }
        }else if(c == '('){
            push2(c);
        }else if(c == ')'){
            while((b = pop2()) != '('){
                printf("%c",b);
            }
        }
    }
    while((c = pop2()) != '#')
        printf("%c",c);
    return 0;
}