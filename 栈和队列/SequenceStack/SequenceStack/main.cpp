//
//  main.cpp
//  SequenceStack
//
//  Created by qinge on 16/5/10.
//  Copyright © 2016年 Q. All rights reserved.
//

#include <iostream>

#define MaxSize 100

typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;


extern void InitStack(SqStack * &s);
extern void ClearStack(SqStack * &s);
extern int StackLength(SqStack *s);
extern int StackEmepty(SqStack *s);
extern int Push(SqStack * &s, ElemType e);
extern int Pop(SqStack * &s, ElemType &e);
extern int GetTop(SqStack *s, ElemType &e);
extern void DispStack(SqStack *s);


int main(int argc, const char * argv[]) {
    
    ElemType e;
    SqStack *s;
    printf("(1) 初始化栈 s \n");
    InitStack(s);
    
    printf("(2) 栈 s 为 %s \n", StackEmepty(s) ? "空" : "非空");
    
    printf("(3) 依次进栈元素 a, b, c, d, e \n");
    Push(s, 'a');
    Push(s, 'b');
    Push(s, 'c');
    Push(s, 'd');
    Push(s, 'e');
    printf("(4) 栈 s 为 %s \n", StackEmepty(s) ? "空" : "非空");
    
    printf("(5) 栈的长度: %d \n", StackLength(s));
    
    printf("(6) 从栈顶到栈底 s =  ");
    DispStack(s);
    
    printf("(7) 出栈顺序 \n");
    while (!StackEmepty(s)) {
        Pop(s, e);
        printf(" %c", e);
    }
    printf("\n");
    
    printf("(8) 栈 s 为 %s \n", StackEmepty(s) ? "空" : "非空");
    
    printf("(9) 释放栈 \n");
    ClearStack(s);
    
    return 0;
}
