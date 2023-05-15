#include<stdio.h>
#include<stdlib.h>
#define POSITIVE 0
#define NEGATIVE 1
typedef struct PolyNode{
	int sign;
	int data;
	int power;
	struct PolyNode* next;
	struct PolyNode* before;
} PolyNode;

PolyNode* create();
void output(PolyNode*);

int main(){
	PolyNode *head, *q, *p;
	int power_sign = 0,count = 0,sign,data,a,power,max = -0x7fffffff;
	char c = ' ';
    head = NULL;
	p = (PolyNode*)malloc(sizeof(PolyNode));
	while (c != '\n'){
		if (!count){
			c = getchar();
			if (c == '-'){
				sign = NEGATIVE;
				scanf(" %d", &data);
			}else{
				sign = POSITIVE;
				data = c - '0';
				while(1){
					c = getchar();
					if (c == 'x' || c == ' ' || c == '\n'){
						power_sign = 1;
						break;
					}else{
						a = c - '0';
						data = data * 10 + a;
					}
				}
			}
		}else{
			scanf("%c %d", &c, &data);
			if (c == '-')
				sign = NEGATIVE;
			else
				sign = POSITIVE;
		}
		if (!power_sign)
			c = getchar();
		else
			power_sign = 0;
		if (c != 'x')
			power = 0;
		else{
			c = getchar();
			if (c != '^')
				power = 1;
			else{
				scanf("%d", &power);
				c = getchar();
			}
		}
        p->next = NULL;
		if (count == 0){
			p->before = NULL;
			head = p;
		}else{
			q->next = p;
			p->before = q;
		}
        q = p;
		q->sign = sign;
		q->data = data;
		q->power = power;
		p = (PolyNode*)malloc(sizeof(PolyNode));
		count++;
	}
	free(p);
    count = 0;
    p = head;
    while (p != NULL){
		if (p->power > max)
			max = p->power;
		p = p->next;
	}
    while(1){
        p = head;
        data = 0;
        while (p != NULL){
            if (p->power == max){
                if (p->sign == NEGATIVE)
                    data = data - p->data;
                else
                    data = data + p->data;
            }
            p = p->next;
        }
        if (!data && max > 1){
            max--;
            continue;
        }
        if (!count){
            if ( data < 0 && max > 0){
                printf("%c ", '-');
                data = - data;
            }
            data = data * max;
            if (max > 2){
                max--;
                printf("%dx^%d", data, max);
            }
            else if (max == 2){
                printf("%dx", data);
                max--;
            }
            else if (max == 1){
                printf("%d", data);
                break;
            }else{
                printf("0");
                break;
            }
            count++;
        }else{
            if (data == 0)
                break;
            else if (data < 0){
                printf(" %c ", '-');
                data = -data;
            }else
                printf(" %c ", '+');
            data = data * max;
            if (max > 2){
                max--;
                printf("%dx^%d", data, max);
            }else if (max == 2){
                printf("%dx", data);
                max--;
            }else if (max == 1){
                printf("%d", data);
                break;
            }
        }
	}
	return 0;
}