//
// Created by c1533 on 2022/7/1.
//
#include <iostream>

using namespace std;
/**
 * 双链表：
 * 1个数据域+2个指针域(前后指针)
 * 添加新节点的操作顺序：
 *      1. 新结点后继指向插入对象的后继
 *      2. 插入对象后继的前驱指向新结点
 *      3. 新结点前驱指向被插结点
 *      4. 被插结点后继指向新结点
 *
 * 循环双链表：
 *      表头结点的prev指向尾结点
 *      表尾结点的next指向头结点
 * */
typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == nullptr) return false;
    L->prev = nullptr;  //循环双链表指向自己，即L.prev=L; L.next=L;
    L->next = nullptr;
    return true;
}

bool Empty(DLinkList L) {
    if (L->next == nullptr) {   //循环双链表判空条件：L.next=L;
        printf("列表为空");
        return true;
    } else {
        printf("列表非空");
        return false;
    }
}

// p结点后插
bool InsertNextNode(DNode *p, DNode *s) {
    if (p == nullptr || s == nullptr) return false;
    s->next = p->next;  //先将要插入的结点s的后继指向p的后继
    if (p->next != nullptr) {
        p->next->prev = s;
    }
    s->prev = p;
    p->next = s;    //p的next要最后断开
    return true;
}   //注意指针顺序，不可变

//删除后继结点
bool DeleteNode(DNode *p) {
    if (p == nullptr) return false;
    DNode *q = p->next;       //找p的后继q
    if (q == nullptr) return false;  //p没有后继
    p->next = q->next;
    if (q->next != nullptr)    //q不是最后一个结点
        q->next->prev = p->prev;
    free(q);
    return true;
}//遍历：后向遍历：while(p!=nullptr){p=p.next;} 前向遍历：while(p!=nullptr){p=p.prev;}

void PrintList(DNode *p){
    while(p!=nullptr){
        printf("\n", p->data);
        p=p->next;
    }
}

//删除列表
void DestroyList(DLinkList &L) {
    while (L->next != nullptr) DeleteNode(L);
    free(L);
    L = nullptr;
}

void testDLinkList() {
    DLinkList L;
    InitDLinkList(L);
//    InsertNextNode();
    PrintList(L);
}

int main() {
    testDLinkList();
}
