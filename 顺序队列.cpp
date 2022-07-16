//
// Created by c1533 on 2022/7/14.
//
/**
 * 队列：先入先出后入后出  FIFO
 * 本代码逻辑为：队头队尾指向相同位置，先放入元素后移动指针；
 * 可以优化为：队尾=队头-1，先移动指针，后放入元素
 **/
#include<iostream>

#define MaxSize 10

typedef struct {
    int data[MaxSize];  //静态数组
    int front;  //头指针
    int rear;   //尾指针
    int size;   //解决代码逻辑判空与判满冲突产生的浪费一个空位问题
} Queue;

void InitQueue(Queue &Q) {
    Q.front = 0;
    Q.rear = 0;
    Q.size = 0;
    printf("队列完成初始化\n");
}

bool isEmpty(Queue Q) {
    if (Q.size == 0 || Q.front > Q.rear) {  //出队次数超过入队次数判定
        printf("\nEmpty queue");
        return false;
    } else {
        printf("\nQueue is not empty");
        return true;
    }
}

bool isFull(Queue Q) {
    if (Q.size != MaxSize) {
        printf("\nQueue is not full");
        return false;
    } else {
        printf("\nQueue is full");
        return true;
    }
}

bool DestroyQueue(Queue &Q) {

}

//尾插法
bool InputQueue(Queue &Q, int x) {
    if ((Q.rear + 1) % MaxSize == Q.front) {    //队尾指针在队头指针的前一个，判定为队列已满，否则根据判空规则会判定为空
        printf("\nQueue is full");
        return false;
    }
    Q.data[Q.rear] = x;
    //Q.rear = (Q.rear + 1) % MaxSize;    //用模的方法让队尾指针回到开始的地方，让队列的头空出来(出队)之后可以继续插入->循环队列
    Q.rear++;
    Q.size++;
    printf("\nInput ok");
    return true;
}

bool OutputQueue(Queue &Q, int &x) {
    if (isEmpty(Q)) {
        printf("\nQueue is empty");
        return false;
    }
    x = Q.data[Q.front];
    //Q.front = (Q.front + 1) % MaxSize;  //尾插法的循环队列，数字一直往大走，所以+1
    Q.front++;
    Q.size--;
    printf("\nOutput ok");
    return true;
}

bool GetHead(Queue Q, int &x) {
    if (Q.rear == Q.front) {
        printf("\nEmpty queue");
        return false;
    }
    x = Q.data[Q.front];
    printf("\nHead element is %d", x);
    return true;
}

void testQueue() {
    Queue q;
    InitQueue(q);
    isEmpty(q);
    InputQueue(q, 3);
    InputQueue(q, 4);
    InputQueue(q, 5);
    isEmpty(q);

}

int main() {

}
