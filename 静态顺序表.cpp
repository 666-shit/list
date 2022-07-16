//
// Created by c1533 on 2022/6/30.
//
#include<stdio.h>
#include<iostream>
#define MaxSize 10
using namespace std;

/**
顺序表：顺序存储方式 逻辑相邻 物理位置也相邻
元素之间的关系由存储单元的邻接关系体现
每个数据元素所占空间一样大
第一个元素位置为：LOC(L) 则第二个元素位置为：LOC(L)+1*数据元素大小
数据元素大小：sizeof(ElemType) ElemType: 顺序表中存放数据元素类型，如：
sizeof(int)=48
定义数据类型：typedef struct{
	int num; int people;
} Customer; 则：sizeof(Customer) = 8B

特点：
1. 随机访问，在O(1)时间内找到第i个元素 data[i-1]
2. 存储密度高，每个节点只存储数据元素
3. 拓展容量不方便
4. 插入删除不方便
*/

/**
静态分配
*/
typedef struct {
    int data[MaxSize];	//静态数组存放数据元素 各个数据元素分配连续的存储空间，大小为MaxSize*sizeof(Elemtype)  本行ElemType为int
    int length;	//当前表长
}SqList;	//顺序表类型定义

//基本操作——初始化顺序表
void InitList(SqList &L) {
    for (int & i : L.data) {
        i = 0;	//所有数据元素设置为默认初始值
    }
//    L.data[0] = 1;
//    L.data[1] = 2;
//    L.data[2] = 3;
//    L.length = 3;	//顺序表初始长度为0
    printf("列表初始化已完成\n");
    //return;
}

//插入y
void Insert(SqList &L, int i, int e) {	// 1 <= i <= length+1
    if (1 <= i && i <= L.length + 1) {
        if (L.length >= MaxSize) {
            printf("超出最大容量\n");
        }
        for (int j = L.length; j >= i; j--) {	//第i个元素与后续元素后移
            L.data[j] = L.data[j - 1];	//后一位赋值前一位
            /*循环次数与问题规模n的关系：
            问题规模 n = L.length
            插入到表尾：不需要移动，最快插入，时间复杂度为O(1)
            插入到表头：移动每一位，最慢插入，时间复杂度为O(n)
            平均：插入到每一个位置的概率相同，i=1, 2, 3 …… length+1的概率都是p=1/(n+1)
                i=1,循环n次，i=2,循环n-1次 …… i=n+1,循环0次
                (1+2+...+n)*p = n/2=O(n)
            */
        }
        L.data[i - 1] = e;		//放入第n个位置，数组下标为n-1
        L.length++;
        printf("插入成功：%d", e);
    }
    else {
        printf("\n非法插入\n");
    }
}

//删除
bool Delete(SqList &L, int i, int &e) {
//返回布尔型变量，方便判断是否删除成功;e为引用型参数，用来返回删除的参数，如果去掉引用符号，则main中打印的还是-1
    if (i<1 || i>L.length) {	//判断删除位置是否合法
        printf("\n删除失败");
        return false;
    }
    e = L.data[i - 1];		//被删除元素复制给e变量对应的内存区域，把删除的元素“带回来”
    for (int j = i; j < L.length; j++) {	//位置i后的元素前移
        L.data[j - 1] = L.data[j];	//时间复杂度同插入，平均循环次数为(n-1)/2，时间复杂度也是O(n)
    }
    L.length--;
    printf("\n删除成功，删除元素为：%d", e);
    return true;
}

//打印列表中所有元素
void PrintList(SqList &L) {
    if (L.length == 0) {
        printf("\n当前为空列表\n");
    }
    else {
        for (int i = 0; i < MaxSize; i++) {
            printf("\ndata[%d]=%d", i, L.data[i]);
        }
        printf("\n列表长度为%d", L.length);
    }
}

//按位查找
int GetElem(SqList L, int i) {	//返回值与数据元素类型相同(这里为int型)
    //判断i值是否合法
    cout << "\n该元素在第" << i+1 << "个位置";
    return L.data[i - 1];	//时间复杂度O(1)
}

int main() {
    SqList L;	//声明一个顺序表
    InitList(L);	//初始化顺序表
    Insert(L, 1, 3);
    PrintList(L);
    GetElem(L, 3);

    int e = -1;
    Delete(L, 1, e);
    PrintList(L);
    GetElem(L, 3);
    return 0;
}
