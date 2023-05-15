#include<stdio.h>
#include<stdlib.h>

typedef struct Glist
{
	char data;
	struct Glist* nextchar;
	struct Glist* lastchar;
} Glist;

int main()
{
	int num,count = 0,sign = 1;
	char array[100],c;
	struct Glist* head = NULL;
    char input;
	Glist* p = NULL;
	Glist* q = (Glist*)malloc(sizeof(Glist));
	while (1){
		scanf("%c", &input);
		if (input != ' '){
			count++;
			if (count == 1){
				q->nextchar = NULL;
				q->lastchar = NULL;
				head = q;
				p = q;
			}else{
				q->nextchar = NULL;
				p->nextchar = q;
				q->lastchar = p;
				p = q;
			}
			p->data = input;
			q = (Glist*)malloc(sizeof(Glist));
		}
		else
			break;
	}
	free(q);
    scanf("%c", &c);
    p = head;
    while (p != NULL){
		if (p->data == c){
			p->lastchar->nextchar = p->nextchar;
			p->nextchar->lastchar = p->lastchar;
		}
		p = p->nextchar;
	}
	p = head;
	while (p != NULL){
		p = p->nextchar;
		count++;
	}
	while(sign){
		sign = 0;
		p = head;
		while (p != NULL){
			if ((p->data == ',') && ((p->nextchar->data == ')')||(p->lastchar->data == '(')||(p->lastchar->data == ','))){
				p->lastchar->nextchar = p->nextchar;
				p->nextchar->lastchar = p->lastchar;
			}
			p = p->nextchar;
		}
		p = head;
		while (p != NULL){
			if ((p->data == '(') && (p->nextchar->data == ')')){
				if ((p == head) || (p->nextchar->nextchar == NULL)){
					head = NULL;
					break;
				}else{
					p->lastchar->nextchar = p->nextchar->nextchar;
					p->nextchar->nextchar->lastchar = p->lastchar;
					p = p->nextchar->nextchar;
				}
			}
			else
				p = p->nextchar;
		}
		num = 0;
		p = head;
		while (p != NULL){
			p = p->nextchar;
			num++;
		}
		if ((count != num) && num){
			count = num;
			sign++;
		}
	}
	p = head;
	if (p == NULL)
		printf("%d",-1);
	else{
		while (p->nextchar != NULL){
			printf("%c", p->data);
			p = p->nextchar;
		}
		printf("%c", p->data);
	}
	return 0;
}
