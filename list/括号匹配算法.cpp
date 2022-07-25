//
// Created by c1533 on 2022/7/16.
//

#include <iostream>

#define MaxSize 10

typedef struct {
    char data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
    printf("\nStack init ok");
}

bool IsEmpty(SqStack S) {
    if (S.top == -1) {
        printf("\nEmpty stack");
        return true;
    } else {
        printf("\nStack not empty");
        return false;
    }
}

bool Push(SqStack &S, char x) {
    if (S.top == MaxSize - 1)   //栈满报错
        return false;
    S.top = S.top + 1;  //指针先加
    S.data[S.top] = x;  //插入元素
    printf("\npush ok");
    return true;
}

bool Pop(SqStack &S, char &x) {
    if (S.top == -1) {
        printf("\nEmpty stack");
        return false;
    }
    printf("\npop element: %d", S.data[S.top]);
    S.top--;
    return true;
}

bool BracketCheck(char str[], int len) {
    SqStack S;
    InitStack(S);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {  //左括号压栈
            Push(S, str[i]);
        } else {    //右括号检测有无匹配项
            if ((IsEmpty(S))) {     //如果栈为空则不匹配
                printf("\nStack is empty but can't match");
                return false;
            }
            char topElem;   //存储弹出的元素
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return IsEmpty(S);      //检测最后栈为空，则匹配成功
}

int main() {
    char str[6] = {'(', '[', ']', '{', '}', ')'};
    BracketCheck(str, 6);
}
