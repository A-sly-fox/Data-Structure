#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXWORD 100
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;
int getch(void){
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
	if(bufp>BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;
}

typedef struct node{
	int data;
	struct node *next;
}list;

int main()
{
	int m,n,i=0;
    char c,word[MAXWORD];
    char *d=word;
    list *ha,*hb,*hc,*p;
    scanf("%d %d",&m,&n);
    int result[m+n];
    while(i<m+n){
        while(isspace(c=getch()))
            ;
        *d++=c;
        for(;;d++)
            if(!isalnum(*d=getch())){
                ungetch(*d);
                break;
            }
        *d='\0';
        result[i]=atoi(word);
        d=word;
        i++;
    }
    ha=NULL;
    i=m-1;
    while(i>=0){
        p=(list*)malloc(sizeof(list));
        p->data=result[i];
        p->next=ha;
        ha=p;
        i--;
    }
    i=m+n-1;
    hb=ha;
    while(i>=m){
        p=(list*)malloc(sizeof(list));
        p->data=result[i];
        p->next=hb;
        hb=p;
        i--;
    }
    hc=hb;
	do{
	   printf("%d ",hc->data);
	   hc=hc->next;
    }while(hc!=NULL);
    return 0;
}
