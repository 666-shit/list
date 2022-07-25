//
// Created by c1533 on 2022/6/30.
//
#include <iostream>

using namespace std;
/**
单链表
定义：
一个单链表节点包含数据元素和指针
不要求大片连续空间，改变容量方便，不可随机存取，消耗空间存放指针

实现方式：
带头结点
不带头结点
*/

/**
struct LNode {	//结点
	int data;	//数据域
	struct LNode *next;	//指针域
};
//增加新结点：malloc申请结点所需空间，指针p指向该结点
struct LNode *p = (struct LNode *)malloc(sizeof(struct LNode));
//typedef关键字——数据类型重命名
typedef struct LNode LNode;	//后续代码不需要带struct，直接写LNode即可
typedef struct LNode LinkList;
*/
//等价于↓
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 静态链表简化定义方式：
 * #def MaxSize 10
 * typedef struct {
 *      int data;
 *      int next;
 * } SLinkList[MaxSize]
 * 等价于：
 * struct Node {
 *      int datal
 *      int next;
 * };
 * typedef struct Node SLinkList[MaxSize];
 * */

bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == nullptr) return false;
    L->next = nullptr;
    return true;
}

/**
 * 尾插法建立单链表
 * 初始化单链表；后插法函数；
 * 设置变量length记录长度；
 * while: 取一个元素e，InsertList(L,length+1,e)查到尾部;length++;
 * ->时间复杂度O(n^2)
 * 解决方法：设置指针始终指向表尾最后一个元素，后插
 * */
LinkList TailInsert(LinkList &L) {
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    LNode *s, *r = L;
//    scanf("%d", &x);
    cin >> x;
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = nullptr;
    printf("\ntail insert ok\n");
    return L;
}

/**
 * 头插法建立单链表
 * 对指定结点(头结点)的后插操作
 * 初始化;
 * while: 每次取元素e;insertnextnode(L,e);
 *
 * 重要应用：列表逆置
 * */
LinkList HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = nullptr;    // 初始为空列表
    /**
     * 只要是初始化单链表，先把头指针指向null
     * */
    cin >> x;
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));  //创建新节点
        s->data = x;
        s->next = L->next;
        L->next = s;  //新节点插入表中，L为头指针
        cin >> x;
    }
    printf("\nhead insert ok\n");
    return L;
}

/**
 * 思考：不带头结点如何实现头插法？
 * */

bool isEmpty(LinkList &L) {
    if (L->next == nullptr) return true;
    else return false;
}

//后插
bool InsertNextNode(LNode *p, int e) {
    if (p == nullptr) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == nullptr) return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    printf("\ninsert ok, element is %d", e);
    return true;
}

bool InsertList(LinkList &L, int i, int e) {
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }
    InsertNextNode(p, e);
}

//前插
bool InsertPriorNode(LNode *p, int e) {
    if (p == nullptr) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == nullptr) return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    printf("\ninsert ok, element is %d", e);
    return true;
}

bool DeleteElem(LNode &L, int i, int e) {
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    p = &L;
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == nullptr) return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

bool DeleteNode(LNode *p) {
    if (p == nullptr) return false;
    LNode *q = p->next;
    p->data = p->next->data;    // 有bug，如果p在最后一个结点，q无data域
    p->next = q->next;
    free(q);
    return true;
}   //实质：把值往前移动一个

// 按位查找，返回第i个元素(带头结点)
LNode *GetElem(LinkList L, int i) {
    if (i < 0) return nullptr;
    LNode *p;
    int j = 0;
    p = L;
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElement(LinkList L, int e) {
    LNode *p = L->next;
    while (p != nullptr && p->data != e) {
        p = p->next;
    }
    return p;
}

int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != nullptr) {
        p = p->next;
        len++;
    }
    printf("\nLength: %d\n", len);
    return len;
}

int main() {
    LinkList L;
    InitList(L);
    TailInsert(L);
    Length(L);
    InitList(L);
    HeadInsert(L);  // 单链表逆置，头插法
    InsertList(L, 1, 1);
    InsertPriorNode(L, 2);
    Length(L);
}
