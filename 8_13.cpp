#include<stdio.h>
#include<stdlib.h>

typedef struct WORD{
	int location;
	int size;
	struct WORD* next;
} word;

int main(){
	char c;
	word *head = NULL,*p,*q;
    int num = 0,a,b,sign;
    p = head;
	for (int i = 0; i < 100; i++){
		c = getchar();
		if (c == '0'){
            p = head;
            q = (word*)malloc(sizeof(word));
            while (p){
                if (p->next)
                    p = p->next;
                else
                    break;
            }
            scanf("%d %d", &a, &b);
            q->next = NULL;
            q->location = a;
            q->size = b;
            if (num == 0)
                head = q;
            else
                p->next = q;
            num++;
        }
		else if (c == '1'){
            sign = 0;
            p = head;
            q = (word*)malloc(sizeof(word));
            scanf("%d %d", &a, &b);
            if ((a + b) < p->location){
                q->location = a;
                q->size = b;
                q->next = head;
                head = q;
            }else if ((a + b) == p->location){
                head->location = a;
                head->size = b + head->size;
            }else{
                while (p->next){
                    if ((a > (p->size + p->location)) && ((a + b) < p->next->location)){
                        q->location = a;
                        q->size = b;
                        q->next = p->next;
                        p->next = q;
                        sign++;
                        break;
                    }else if ((a == (p->size + p->location)) && ((a + b) < p->next->location)){
                        p->size = p->size + b;
                        sign++;
                        break;
                    }else if ((a > (p->size + p->location)) && ((a + b) == p->next->location)){
                        p->next->location = a;
                        p->next->size = p->next->size + b;
                        sign++;
                        break;
                    }
                    else if ((a == (p->size + p->location)) && ((a + b) == p->next->location)){
                        p->size = p->size + p->next->size + b;
                        p->next = p->next->next;
                        sign++;
                        break;
                    }
                    else
                        p = p->next;
                }
                if(!sign){
                    if (a > (p->size + p->location)){
                        q->location = a;
                        q->size = b;
                        q->next = NULL;
                        p->next = q;
                    }else{
                        p->size = p->size + b;
                    }
                }
            }
        }
        else if (c == '\n')
            continue;
		else
			break;
        getchar();
	}
	p = head;
    while (p->next){
        printf("0");
        printf(" %d %d\n", p->location, p->size);
        p = p->next;
    }
    printf("0");
    printf(" %d %d\n", p->location, p->size);
	return 0;
}