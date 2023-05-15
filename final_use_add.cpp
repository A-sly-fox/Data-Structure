#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

typedef  struct  BSTNode{  
  int data;
  int bf;
  struct  BSTNode  *lchild , *rchild;
} BSTNode, *BSTree; 

BSTNode* parent(BSTNode *head,BSTNode *p){
    if(p == head || p == NULL)
        return NULL;
    BSTNode *r,*s,*q;
    q = head; r = NULL; s = NULL;
    if(q->lchild == p){
        return q;
    }else if(q->rchild  == p){
        return q;
    }else{
        if(q->lchild){
            r = parent(q->lchild,p);
            if(r != NULL)
                return r;
        }
        if(q->rchild){
            s = parent(q->rchild,p);
            if(s != NULL)
                return s;
        }
    }
}

void R_Rotate(BSTree p, BSTree parent){
    BSTree lc; 
    lc = p->lchild;
    p->lchild = lc->rchild;
    lc->rchild = p; 
    p = lc;
    if(parent->data > p->data)
        parent->lchild = p;
    else
        parent->rchild = p;
}

void L_Rotate(BSTree p, BSTree parent){
    BSTree rc; 
    rc = p->rchild;
    p->rchild = rc->lchild; 
    rc->lchild = p;
    p = rc;
    if(parent->data > p->data)
        parent->lchild = p;
    else
        parent->rchild = p;
}

void LR_Rotate (BSTree p, BSTree parent){
    BSTree lc,rc;
    rc = p;
    lc = rc->lchild;
    p = lc->rchild;
    lc->rchild = p->lchild;
    p->lchild = lc;
    rc->lchild = p->rchild;
    p->rchild = rc;
    if(parent->data > p->data)
        parent->lchild = p;
    else
        parent->rchild = p;
}

void RL_Rotate (BSTree p, BSTree parent){
    BSTree lc,rc;
    lc = p;
    rc = lc->rchild;
    p = rc->lchild;
    rc->lchild = p->rchild;
    p->rchild = rc;
    lc->rchild = p->lchild;
    p->lchild = lc;
    if(parent->data > p->data)
        parent->lchild = p;
    else
        parent->rchild = p;
}

BSTNode* pResult = NULL;
BSTNode* search_function(int i,BSTNode* pNow){
	if (pNow != NULL){
		if (pNow->data != i){
			if (pNow->lchild != NULL)
				search_function(i, pNow->lchild);
			if (pNow->rchild != NULL)
				search_function(i, pNow->rchild);
		}else{
			pResult = pNow;
            return pResult;
        }
	}else{
        return NULL;
    }
}

void myprint(BSTNode *p,int deepth){
    if(!p)
        return;
	BSTNode* pNew = p;
	int i;
	for (i = 0; i < deepth; i++)
		printf("-");
	printf("\t%d\tbf:%d\n", pNew->data, pNew->bf);
	if (pNew->lchild != NULL)
		myprint(pNew->lchild, deepth + 1);
	if (pNew->rchild != NULL)
		myprint(pNew->rchild, deepth + 1);
}

int cal_height(BSTNode *p){
    int a,b,max;
    if(p == NULL){
        return 0;
    }else{
        a = cal_height(p->lchild)+1;
        b = cal_height(p->rchild)+1;
        return (a>b)?a:b;
    }
}

void cal_bf(BSTNode *p){
    if(p == NULL){
        return;
    }else{
        p->bf = cal_height(p->lchild) - cal_height(p->rchild);
        cal_bf(p->lchild);
        cal_bf(p->rchild);
    }
}

static int sign = 0;
void search(BSTNode *p, int x){
    if(p == NULL)
        return;
    if(p->data == x)
        sign ++;
    else if(p->data > x)
        search(p->lchild,x);
    else
        search(p->rchild,x);
}

BSTNode *add;
void insert(BSTNode *p, int data){
    if(p->data == data){
        printf("%d has already existed!\n");
    }else if(p->data < data){
        if(p->rchild == NULL){
            p->rchild = (BSTNode *)malloc(sizeof(BSTNode));
            p->rchild->data = data;
            p->rchild->lchild = p->rchild->rchild = NULL;
            add = p->rchild;
        }else
            insert(p->rchild,data);
    }else{
        if(p->lchild == NULL){
            p->lchild = (BSTNode *)malloc(sizeof(BSTNode));
            p->lchild->data = data;
            p->lchild->lchild = p->lchild->rchild = NULL;
            add = p->lchild;
        }else
            insert(p->lchild,data);
    }
    cal_bf(p);
}

BSTNode *mydel;
void mydelete(BSTNode *head,BSTNode *p, int data){
    BSTNode *del,*parent2;
    parent2 = parent(head,p);
    if(p->data < data){
        if(p->rchild == NULL)
            printf("%d is not in the tree!\n",data);
        else
            mydelete(head,p->rchild,data);
    }else if(p->data > data){
        if(p->lchild == NULL)
            printf("%d is not in the tree!\n",data);
        else
            mydelete(head,p->lchild,data);
    }else{
        if(!p->lchild){
            if(parent2->data > p->data)
                parent2->lchild = p->rchild;
            else
                parent2->rchild = p->rchild;
            mydel = parent2;
        }else if(!p->rchild){
            if(parent2->data > p->data)
                parent2->lchild = p->lchild;
            else
                parent2->rchild = p->lchild;
            mydel = parent2;
        }else{
            del = p->lchild;
            while(del->rchild != NULL)
                del = del->rchild;
            mydel = parent(head,del);
            if(p->lchild != del)
                del->lchild = p->lchild;
            del->rchild = p->rchild;
            if(mydel->data > del->data)
                mydel->lchild = NULL;
            else
                mydel->rchild = NULL;
            if(parent2->data > p->data)
                parent2->lchild = del;
            else
                parent2->rchild = del;
            mydel = del;
            free(p);
        }
    }
}

void insert_balance(BSTNode *p,BSTNode *head){
    BSTNode *q,*r,*s;
    q = parent(head,p);
    r = parent(head,q);
    s = parent(head,r);
    while(r && r != head){
        if(q->bf == 1 && q->data > p->data){
            if(r->bf == 2 && r->data > q->data)
                R_Rotate(r,s);
            else if(r->bf == -2 && r->data < q->data)
                RL_Rotate(r,s);
        }else if(q->bf == -1 && q->data < p->data){
            if(r->bf == 2 && r->data > q->data)
                LR_Rotate(r,s);
            else if(r->bf == -2 && r->data < q->data)
                L_Rotate(r,s);
        }
        cal_bf(head->lchild);
        p = parent(head,p);
        q = parent(head,p);
        r = parent(head,q);
        s = parent(head,r);
    }
    return;
}

void delete_balance(BSTNode *p,BSTNode *head){
    if(p == NULL)
        return;
    BSTNode *q;
    q = parent(head,p);
    while(p != head){
        if(p->bf == 2){
            if(p->lchild && p->lchild->bf == 1)
                R_Rotate(p,q);
            else if(p->lchild && p->lchild->bf == -1)
                LR_Rotate(p,q);
        }else if(p->bf == -2){
            if(p->rchild && p->rchild->bf == -1)
                L_Rotate(p,q);
            else if(p->rchild && p->rchild->bf == 1)
                RL_Rotate(p,q);
        }
        p = q;
        q = parent(head,p);
    }
}

int main(){
    BSTNode *root,*p,*head;
    int kind,data;
    root = NULL;
    head = (BSTNode *)malloc(sizeof(BSTNode));
    head->rchild = NULL;
    head->data = 0x7fffffff;
    for(;;){
        printf("What kind of operation?\n");
        printf("1: search\t2: insert\t3:selete\t4: quit\n");
        scanf("%d", &kind);
        if(kind == 4)
            return 0;
        printf("input the data to be operated on:\n");
        scanf("%d", &data);
        switch (kind){
            case 1:
                sign = 0;
                search(root,data);
                printf((sign)?"True\n":"False\n");
                cal_bf(root);
                myprint(root,0);
                break;
            
            case 2:
                if(root == NULL){
                    root = (BSTNode *)malloc(sizeof(BSTNode));
                    root->data = data;
                    root->lchild = root->rchild = NULL;
                    root->bf = 0;
                    head->lchild = root;
                }else{
                    insert(root,data);
                    //printf("after insert:\n");
                    //myprint(root,0);
                    //printf("\n");
                    printf("after balance operation:\n");
                    insert_balance(add,head);
                }
                root = head->lchild;
                cal_bf(root);
                myprint(root,0);
                break;

            case 3:
                if(!root)
                    printf("There is no tree existed!\n");
                mydelete(head,root,data);
                root = head->lchild;
                cal_bf(root);
                //printf("after delete\n");
                //myprint(root,0);
                //printf("\n");
                printf("after balance operation:\n");
                delete_balance(mydel,head);
                root = head->lchild;
                cal_bf(root);
                myprint(root,0);
                break;

            default:
                printf("Unknow command, please try again!\n");
                break;
        }
        printf("\n\n\n\n\n\n");
    }
    return 0;
}