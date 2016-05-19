//
//  LinkStack.cpp
//  LinkStack
//
//  Created by qinge on 16/5/17.
//  Copyright © 2016年 snqu. All rights reserved.
//

#include "LinkStack.hpp"
#include <stdlib.h>
#include <stdio.h>

typedef char ElemType;
typedef struct linknode{
    ElemType data;
    struct linknode * next;
}LiStack;


void InitStack(LiStack * &s){
    s = (LiStack *)malloc(sizeof(LiStack));
    s -> next = NULL;
}

void ClearStack(LiStack * &s){
    LiStack *p = s -> next;
    while (p != NULL) {
        free(s);
        s = p;
        p = p -> next;
    }
}

int StackLength(LiStack * s){
    int i = 0;
    LiStack *p;
    p = s -> next;
    while (p != NULL) {
        i++;
        p = p -> next;
    }
    return i;
}

int StackEmpty(LiStack *s){
    return (s -> next == NULL);
}

/**
 *  s -> next 始终是指向栈顶的
 *
 *  @param s
 *  @param e
 */
void Push(LiStack * &s, ElemType e){
    LiStack *p;
    p = (LiStack *)malloc(sizeof(LiStack));
    p -> data = e;
    
    p -> next = s -> next;
    s -> next = p;
    
}



int Pop(LiStack * &s, ElemType &e){
    LiStack *p;
    if (s -> next == NULL) {
        return 0;
    }
    p = s -> next; // p 指向栈顶
    e = p -> data;
    
    s -> next = p -> next;
    free(p);
    return 1;
}


int GetTop(LiStack *s, ElemType &e){
    if (s -> next == NULL) {
        return 0;
    }
    e = s -> next -> data;
    return 1;
}

void DispStack(LiStack *s){
    LiStack *p = s -> next;
    while (p != NULL) {
        printf(" %c", p -> data);
        p = p -> next;
    }
    printf("\n");
}



