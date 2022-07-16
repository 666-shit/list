//
// Created by c1533 on 2022/7/16.
//
#include <iostream>

#define MaxSize 10
typedef struct LinkNode {    //链式队列结点
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {     //链式队列
    LinkNode *front, *rear;     //队列的队头和队尾指针
} LinkQueue;

//初始化带头结点队列
void InitQueue(LinkQueue &Q) {
    //初始化时指针都指向头结点，如果不带头结点，则指向nullptr
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = nullptr;
    printf("\n初始化完成");
}

bool isEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {   //如果不带头结点则判断是否为nullptr
        printf("\nEmpty queue");
        return true;
    } else {
        printf("\nQueue is not empty");
        return false;
    }
}

//带头结点入队
void Insert(LinkQueue &Q, int x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;    //因为s是最后一个，所以next指向nullptr
    //不带头结点的队列：要判断Q.front和Q.rear指向的是否为空，若为空，直接修改指针到s
    Q.rear->next = s;     //新结点插入到rear之后
    Q.rear = s;       //修改表尾指针
}

bool OutputQueue(LinkQueue &Q, int &x) {
    if (Q.front == Q.rear) {
        printf("\nQueue is empty");
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;      //队头先出，头结点的后一个元素
    Q.front->next = p->next;      //修改头结点的next指针
    if (Q.rear == p)       //此次是最后一个结点出队
        Q.rear = Q.front;     //修改rear指针
    free(p);
    printf("\nOutput: %d", x);
    return true;
}//队列一般不会满

void testLinkQueue() {
    LinkQueue Q;
    InitQueue(Q);
    isEmpty(Q);
    Insert(Q, 3);

}

int main() {
    testLinkQueue();
}