#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

typedef  struct  BSTNode{  
  int data;
  int bf;
  struct  BSTNode  *lchild , *rchild;
} BSTNode, *BSTree; 

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
	BSTNode* pNew = p;
	int i;
	for (i = 0; i < deepth; i++)
		printf("-");
	printf("%d:%d\n", pNew->data, pNew->bf);
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

int vex[MAX];
int left[MAX];
int right[MAX];
int result[MAX];

void createtree(BSTNode *p, int a){
    p->data = vex[a];
    if(left[a] == -1){
        p->lchild = NULL;
    }else{
        p->lchild = (BSTNode *)malloc(sizeof(BSTNode));
        createtree(p->lchild,left[a]);
    }
    if(right[a] == -1){
        p->rchild = NULL;
    }else{
        p->rchild = (BSTNode *)malloc(sizeof(BSTNode));
        createtree(p->rchild,right[a]);
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
            add = p;
        }else
            insert(p->rchild,data);
    }else{
        if(p->lchild == NULL){
            p->lchild = (BSTNode *)malloc(sizeof(BSTNode));
            p->lchild->data = data;
            p->lchild->lchild = p->lchild->rchild = NULL;
            add = p;
        }else
            insert(p->lchild,data);
    }
    cal_bf(p);
}

BSTNode* parent(BSTNode *head,BSTNode *p){
    if(p == head)
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

void insert_balance(BSTNode *p,BSTNode *head){
    if(p == NULL)
        return;
    BSTNode *q;
    q = parent(head,p);
    if(p->bf == 2){
        if(p->lchild->bf == 1)
            R_Rotate(p,q);
        else
            LR_Rotate(p,q);
    }else if(p->bf == -2){
        if(p->rchild->bf == -1)
            L_Rotate(p,q);
        else
            RL_Rotate(p,q);
    }else{
        insert_balance(p->lchild,head);
        insert_balance(p->rchild,head);
    }
}

/*Status InsertAVL(BSTree &T, ElemType e, Boolean &taller) {
//若在平衡的二叉排序树T中不存在和e有相同关键字的结点， 
//则插入一个数据元素为e的新结点，并返回1，否则返回0。 
//若因插入而使二叉排序树失去平衡，则作平衡旋转处理， 
//布尔变量taller反映T长高与否 
if (!T) { //插入新结点，树"长高"，置taller为TRUE
	T = (BSTree) malloc (sizeof(BSTNode)); 
	T->data = e; T->lchild = T->rchild = NULL;
	T->bf = EH; taller = TRUE; } 
else {
   if (EQ(e.key, T->data.key)) {
   	// 树中已存在和e有相同关键字的结点  
  	taller = FALSE; return 0; } // 则不再插入
    if (LT(e.key, T->data.key)) {
    // 应继续在T的左子树中进行搜索 
        if (InsertAVL(T->lchild, e, taller)==0) return 0; // 未插入
        if (taller) //插入到T的左子树中且左子树"长高“
        switch (T->bf) { // 检查T的平衡度 
        case LH: //原本左子树比右子树高，需作左平衡处理 
                LeftBalance(T); taller = FALSE; break; 
        case EH: //原本左、右子树等高
                //现因左子树增高而使树增高 
                T->bf = LH; taller = TRUE; break; 
        case RH: //原本右子树比左子树高
                //现左、右子树等高 
                T->bf = EH; taller = FALSE; break;
        } // switch (T->bf) 
    } // if
    else { // 应继续在T的右子树中进行搜索
        if (InsertAVL(T->rchild, e, taller)==0) return 0; 
        if (taller) //已插入到T的右子树且右子树长高 
        switch (T->bf) { //检查T的平衡度
            case LH: //原本左子树比右子树高
                //现左、右子树等高
                T->bf = EH; taller = FALSE; break; 
            case EH: //原本左、右子树等高
                //现因右子树增高而使树增高
                T->bf = RH; taller = TRUE; break; 
            case RH: //原本右子树比左子树高
                    //需要作右平衡处理 
                RightBalance(T); taller = FALSE; break; 
            } //switch (T->bf)
        } //else 
        } // else 
    return 1; 
} //InsertAVL*/




int main(){
    BSTNode *root,*p,*head;
    int kind,data;
    root = NULL;
    head = (BSTNode *)malloc(sizeof(BSTNode));
    head->rchild = NULL;
    head->data = 0x7fffffff;
    /*root = (BSTNode *)malloc(sizeof(BSTNode));
    int count=0,point=0,num=0;
    while(scanf("%d",&vex[count]) != EOF){
        scanf("%d %d",&left[count],&right[count]);
        count++;
    }
    p = root;
    createtree(p,0);*/
    kind = 2;
    /*printf("What kind of operation?\n");
    printf("1: search\t2: insert\t3:selete\t4: quit\n");
    scanf("%d", &kind);
    if(kind == 4)
        return 0;*/
    for(;;){
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
                    printf("after insert\n");
                    myprint(root,0);
                    printf("\n");
                    insert_balance(root,head);
                }
                root = head->lchild;
                cal_bf(root);
                myprint(root,0);
                break;

            case 3:
                
                break;

            default:
                break;
        }
    }
    return 0;
}