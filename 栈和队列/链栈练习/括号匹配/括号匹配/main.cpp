//
//  main.cpp
//  括号匹配
//
//  Created by qinge on 16/5/19.
//  Copyright © 2016年 snqu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

template <class T>

int getArrayLen(T& array) {
    //使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度
    return (sizeof(array) / sizeof(array[0]));
}

typedef char ElemType;
typedef struct linknode{
    ElemType data;
    struct linknode * next;
}LiStack;

extern void InitStack(LiStack * &s);
extern void ClearStack(LiStack * &s);
extern int StackLength(LiStack * s);
extern int StackEmpty(LiStack *s);
extern void Push(LiStack * &s, ElemType e);
extern int Pop(LiStack * &s, ElemType &e);
extern int GetTop(LiStack *s, ElemType &e);
extern void DispStack(LiStack *s);

int Match(char exp[], int n);

int main(int argc, const char * argv[]) {
    
    string s = "(1+2) + 3 + (-3) - 10";
    ElemType exp[30];
    strcpy(exp, s.c_str());
    bool match = Match(exp, getArrayLen(exp));
    if (match) {
        printf("括号匹配 \n");
    }else{
        printf("括号 不 匹配 \n");
    }
    
    return 0;
}



/**
 *  假设表达式只有左右圆括号 判断括号是否匹配
 *
 *  @param exp
 *  @param n   exp length
 *
 *  @return
 */
int Match(char exp[], int n){
    int i = 0;
    char e;
    LiStack *s;
    InitStack(s);
    while ( i < n ) {
        if (exp[i] == '(') {
            Push(s, exp[i]);
        }else if (exp[i] == ')'){
            if (GetTop(s, e) == 1) {
                if (e != '(') {
                    return 0; // 不匹配
                }else{
                    Pop(s, e);
                }
            }else{
                return 0;
            }
        }
        i++;
    }
    if (StackEmpty(s) == 1) {
        return 1; // 匹配完成 栈也为空 说明括号匹配
    }
    return 0;
}


