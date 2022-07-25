//
// Created by c1533 on 2022/7/25.
//
/**
 * 串
 * */
#define  MaxLen 255
typedef struct {
    char ch[MaxLen];    //静态数组实现定长存储
    int length;
} SString;

//typedef struct {
//    char *ch;       //动态数组实现堆分配，按串长分配存储区，ch指向串的基础地址
//    int length;
//} HString;
//HString S;
//S.ch = (char *) malloc(MaxLen*sizeof(char));
//S.length = 0;
//串的链式存储
//typedef struct StringNode {
//    char ch[4];     //每个字符1B，每个结点存储多个字符，增加存储密度
//    struct StringNode *next;    //每个指针4B
//}StringNode, *String;

/**求子串*/
bool SubSreing(SString &Sub, SString S, int pos, int len) {
    if (pos + len - 1 > S.length) {     //越界判断
        return false;
    }
    for (int i = pos; i < pos + len; i++) {     //取出字符放入S
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

/**比较字符串*/
int StrCompare(SString S, SString T) {       //S大于T，返回正值，小于返回负值，等于返回0
    for (int i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i]) {       //如果串同一位置的字符不相同，则比大小
            return S.ch[i] - T.ch[i];
        }
    }
    //扫描过的所有字符串都一样，则长度达的串更大
    return S.length - T.length;
}

/**定位元素*/
int Index(SString S, SString T) {
    int i = 1, n = S.length, m = T.length;
    SString sub;        //暂存子串
    while (i <= n - m + 1) {
        SubSreing(sub, S, i, m);
        if (StrCompare(sub, T) != 0) {      //如果匹配成功，根据该函数，应该返回0
            i++;
        } else {
            return i;       //返回字串在主串中位置，匹配成功
        }
    }
    return 0;       //S中不存在与T相等的字串，匹配失败
}

/**
 * 朴素匹配算法：
 * 主串长度n，模式串长度m，
 * 将主串中所有长度为m的字串依次与模式串对比，
 * 直到找到一个完全匹配的字串或都不匹配为止
 * 最多对比n-m+1个子串
 * */
int Indexpusu(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;        //主串指针回溯到下一个字串的起始位置
            j = 1;        //模式串回到开头
        }
    }
    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}   //最坏时间复杂度O(m*n)

/**KMP算法：
 * 当第6个元素匹配失败时，可令主串指针i不变，模式串指针j=3;
 * ...5...j=2; ...4...j=2;
 * ...3...j=1; ...2...j=1;
 * ...1...匹配下一个相邻子串，j=0,i++,j++;
 * 优点：i不用再回溯，模式串指针的回溯位移可以用数组表示，next[6]=3表示...6...j=3，以此类推
 * 当next[1]时，先让j=0，再执行后续
 * if(S[i]!=T[j]) j=next[j]; if(j==0) {i++;j++}
 * 思路：根据模式串T求出next数组->利用next数组进行匹配，主串指针不回溯
 * */
int Index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {     //如果可以匹配，或j=0(及next[1])
            i++;
            j++;
        } else {        //无法匹配
            j = next[j];
        }
    }
    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}       //最坏时间复杂度O(m+n)














