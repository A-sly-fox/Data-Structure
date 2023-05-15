#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data,freq,sort,sort2;
	struct Node* next;
	struct Node* prior;
} link;

int main(){
	link *p, *q, *head, *r, *s;
	int a,length,b,c=1;
	scanf("%d", &length);
	head = (link *)malloc(sizeof(link));
    head->next  = head;
    head->prior = head;
    head->freq = 0;
    head->sort = 1;
    head->sort2 = 0;
    scanf("%d", &a);
    head->data = a;
    p = head;
    for (int i = 1; i < length; i++){
        q = (link *)malloc(sizeof(link));
        scanf("%d", &a);
        q->data = a;
        q->next  = head;
        q->prior = p;
        q->freq = 0;
        q->sort = 0;
        q->sort2 = 0;
        p->next  = q;
        head->prior = q;
        p = q;
    }
    while ((scanf("%d", &a) != EOF)){
        p = head;
        for(int i = 0; i < length; i++){
            if(p->data == a){
                p->freq ++;
                if(!p->sort2)
                    p->sort2 = c++;
                break;
            }
            p = p->next;
        }
        r = p;
        if(r == head){
            ;
        }else if(r->freq > head->freq || (r->freq == head->freq && r->sort2 < head->sort2)){
            r->prior->next = r->next;
            r->next->prior = r->prior;
            r->prior = head->prior;
            head->prior->next = r;
            head->prior = r;
            r->next = head;
            head = r;
        }else{
            q = head;
            while(q->next != head){
                if(r == q){
                    break;
                }else if(r->freq < q->freq && r->freq > q->next->freq){
                    r->prior->next = r->next;
                    r->next->prior = r->prior;
                    r->next = q->next;
                    q->next->prior = r;
                    q->next = r;
                    r->prior = q;
                    break;
                }else if(r->freq < q->freq && r->freq == q->next->freq && r->sort2 <= q->next->sort2){
                    r->prior->next = r->next;
                    r->next->prior = r->prior;
                    r->next = q->next;
                    q->next->prior = r;
                    q->next = r;
                    r->prior = q;
                    r->sort++;
                    break;
                }else if(r->freq == q->freq && r->freq == q->next->freq && r->sort2 > q->sort2 && r->sort2 <= q->next->sort2){
                    r->prior->next = r->next;
                    r->next->prior = r->prior;
                    r->next = q->next;
                    q->next->prior = r;
                    q->next = r;
                    r->prior = q;
                    r->sort++;
                    break;
                }else if(r->freq == q->freq && r->freq > q->next->freq && r->sort2 > q->sort2){
                    r->prior->next = r->next;
                    r->next->prior = r->prior;
                    r->next = q->next;
                    q->next->prior = r;
                    q->next = r;
                    r->prior = q;
                    r->sort++;
                    break;
                }
                q = q->next;
            }
            if(q->next == head){
                r->prior->next = r->next;
                r->next->prior = r->prior;
                r->next = q->next;
                q->next->prior = r;
                q->next = r;
                r->prior = q;
                r->sort++;
            }
        }
    }

    p = head;
    while(p->next != head){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("%d",p->data);
	return 0;
}