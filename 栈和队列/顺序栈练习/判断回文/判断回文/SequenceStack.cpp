//
//  SequenceStack.cpp
//  SequenceStack
//
//  Created by qinge on 16/5/10.
//  Copyright © 2016年 Q. All rights reserved.
//

#include "SequenceStack.hpp"
#include <stdlib.h>


#define MaxSize 100

typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;


/**
 *  初始化栈 栈顶指针指向 -1 即可
 *
 *  @param s
 */
void InitStack(SqStack * &s){
    s = (SqStack *)malloc(sizeof(SqStack));
    s -> top = -1;
}

void ClearStack(SqStack * &s){
    free(s);
}


int StackLength(SqStack *s){
    return (s -> top + 1);
}

int StackEmepty(SqStack *s){
    return s -> top == -1;
}

int Push(SqStack * &s, ElemType e){
    if (s -> top == MaxSize - 1) {
        return 0;
    }
    s -> top++;
    s -> data[s -> top] = e;
    return 1;
}

int Pop(SqStack * &s, ElemType &e){
    if (s -> top == - 1) {
        return 0;
    }
    e = s -> data[s -> top];
    s -> top --;
    return 1;
}

int GetTop(SqStack *s, ElemType &e){
    if (s -> top == - 1) {
        return 0;
    }
    e = s -> data [s -> top];
    return 1;
}

void DispStack(SqStack *s){
    int i;
    for (i = s -> top; i >= 0; i--) {
        printf(" %c", s -> data[i]);
    }
    printf("\n");
}









