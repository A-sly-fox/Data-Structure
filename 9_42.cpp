#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXKEYLEN 100

typedef struct key{
    char ch[MAXKEYLEN];
    int num;
} KeysType;

typedef struct TrieNode {
    int a[27];
    struct TrieNode *ptr[27];
} TrieNode, *TrieTree;

void zero(char *a,int length){
    for (int i = 0; i < length; i++)
        a[i] = 0;
}

int main(){
    int a,sign;
    TrieNode *head, *p, *q;
    head = (TrieNode *)malloc(sizeof(TrieNode));
    for(int i = 0;i < 27; i++){
        head->ptr[i] = NULL;
        head->a[i] = 0;
    }
    char mystring[MAXKEYLEN];
    zero(mystring,MAXKEYLEN);
    while((scanf("%d %s", &a, mystring)) != EOF){
        switch (a)
        {
        case 1:
            p = head;
            for(int j=0;j<strlen(mystring);j++){
                if(p->ptr[mystring[j]-'a']){
                    if(j == strlen(mystring)-1)
                        p->a[mystring[j]-'a'] = 1;
                    p = p->ptr[mystring[j]-'a'];
                }
                else{
                    q = (TrieNode *)malloc(sizeof(TrieNode));
                    for(int i = 0;i < 27; i++){
                        q->ptr[i] = NULL;
                        q->a[i] = 0;
                    }
                    p->ptr[mystring[j]-'a'] = q;
                    if(j == strlen(mystring)-1)
                        p->a[mystring[j]-'a'] = 1;
                    p = p->ptr[mystring[j]-'a'];
                }
                
            }
            break;
        
        case 2:
            p = head;
            for(int j=0;j<strlen(mystring);j++){
                if(j != strlen(mystring)-1)
                    p = p->ptr[mystring[j]-'a'];
                else{
                    p->a[mystring[j]-'a'] = 0;
                }
            }
            break;

        case 3:
            sign = 0;
            p = head;
            for(int j=0;j<strlen(mystring);j++){
                if(j != strlen(mystring)-1){
                    if(p->ptr[mystring[j]-'a'] == NULL){
                        sign++;
                        break;
                    }
                    p = p->ptr[mystring[j]-'a'];
                }else{
                    if(!p->a[mystring[j]-'a'])
                        sign++;
                }
            }
            printf((sign)?"False\n":"True\n");
            break;
        
        default:
            break;
        }
        zero(mystring,MAXKEYLEN);
    }
}