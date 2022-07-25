//
// Created by c1533 on 2022/7/12.
//
/**
 * 栈：先入后出，后入先出; LIFO
 * 共享栈：两个栈共享同一片空间
 * */
#include <iostream>

# define MaxSize 10
using namespace std;

typedef struct {
    int data[MaxSize];  //静态数组中存放栈元素
    int top;    //栈顶指针  共享栈定义栈顶指针：int top0; int top1;
} SqStack;

void InitStack(SqStack &S) {
    S.top = -1; //初始化栈顶指针
    //共享栈初始化：S.top0=-1; S.top1=MaxSize;
    printf("\nStack init ok");
}

bool isEmpty(SqStack S) {
    if (S.top == -1) {
        printf("\nEmpty stack");
        return true;
    } else {
        printf("\nStack not empty");
        return false;
    }
}

bool Push(SqStack &S, int x) {
    if (S.top == MaxSize - 1)   //栈满报错
        return false;
    S.top = S.top + 1;  //指针先加
    S.data[S.top] = x;  //插入元素
    printf("\npush ok");
    return true;
}

void printAllStack(SqStack S) {
    if (S.top == -1) {
        printf("\nEmpty stack");
    }
    for (int i = 0; i < S.top + 1; i++) {
        printf("\nS.data[i] =%d", S.data[i]);
    }
}

bool findElem(SqStack S, int e) {
    if (S.top == -1) {
        printf("\nEmpty stack");
        return false;
    }
    for (int i = 0; i < S.top + 1; i++) {
        if (S.data[i] == e) {
            printf("\n元素：%d 在第 [%d] 个位置", e, i + 1);
        }
    }
    return true;
}

bool Pop(SqStack &S) {
    if (S.top == -1) {
        printf("\nEmpty stack");
        return false;
    }
    printf("\n删除元素：%d", S.data[S.top]);
    S.top--;
    return true;
}

int getLength(SqStack S) {
    if (S.top == -1) {
        printf("\nEmpty stack");
    }
    printf("\nStack length is %d", S.top + 1);
}

void testStack() {
    SqStack s;
    InitStack(s);
    isEmpty(s);
    Push(s, 1);
    Push(s, 3);
    Push(s, 5);
    isEmpty(s);
    printAllStack(s);
    findElem(s, 3);
    Pop(s);
    Push(s, 3);
    Push(s, 5);
    Push(s, 3);
    Pop(s);
    printAllStack(s);
    getLength(s);
}

int main() {
    testStack();
}
