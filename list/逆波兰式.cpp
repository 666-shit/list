//
// Created by c1533 on 2022/7/21.
//
/**
 * 后缀转中缀式，左侧运算符优先原则，如：
 * 后缀式计算：（用栈实现）
 * 1. 从左往右扫描下一个元素，直到处理完所有元素
 * 2. 若扫描到操作数则压入栈，回到1，否则执行三
 * 3. 若扫描到运算符，则弹出两个栈顶元素，执行相应运算，运算结果压回栈顶，回到1（先出栈的元素在右侧）
 *
 * 前缀转中缀式，右侧运算符优先为原则，如：a+b*(c-d)-e/f = +a-*b-cd/ef
 *前缀式计算：
 * 从右往左扫描
 * 后续同上
 *
 * 中缀转后缀：
 * 初始化栈，保存暂时不能确定运算顺序的运算符
 * 从左到右 处理各个元素直到末尾，出现三种情况：
 * 1. 遇到操作数，直接加入后缀表达式
 * 2. 遇到界限符，遇到"("直接入栈，遇到")"则依次弹出栈内运算符并加入后缀表达式，直到弹出"("为止。"("不加入后缀表达式
 * 3. 遇到运算符，依次弹出栈中优先级高于或等于当前运算符的所有运算符，并加入后缀表达式，若碰到"("或栈空则停止。之后在把当前运算符入栈
 * 处理完所有字符后，将栈中剩余运算符依次弹出栈并加入后缀表达式
 *
 * 用栈实现中缀表达式的计算：
 * 初始化两个栈，操作数栈和运算符栈
 * 扫描到操作数，压入操作数栈
 * 扫描到运算符或界限符，按照中缀转后缀的逻辑亚服运算符栈
 * （期间会弹出运算符，每当弹出一个运算符时，
 * 就需要再弹出两个操作数栈的栈顶元素并执行相应运算，运算结果再压回操作数栈）
 * */













