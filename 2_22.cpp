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
	char data[MAXWORD];
	struct node *next;
}list;

int main()
{
	int i;
    char c=',',word[MAXWORD];
    char *d=word;
    list *ha,*hb,*p;
    ha=NULL;
    while(c==','){
        c=getch();
        *d++=c;
        for(;;d++)
            if(!isalnum(*d=(c=getch()))){
                break;
            }
        *d='\0';
        p=(list*)malloc(sizeof(list));
        for(i=0;i<MAXWORD;i++)
            p->data[i]=word[i];
        p->next=ha;
        ha=p;
        d=word;
    }
    hb=ha;
	do{
	   printf("%s,",hb->data);
	   hb=hb->next;
    }while(hb->next!=NULL);
    printf("%s",hb->data);
    return 0;
}
