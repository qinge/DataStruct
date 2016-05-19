//
//  main.cpp
//  LinkStack
//
//  Created by qinge on 16/5/17.
//  Copyright © 2016年 snqu. All rights reserved.
//

#include <iostream>

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


int main(int argc, const char * argv[]) {
    
    ElemType e;
    LiStack *s;
    printf("(1) 初始化链栈s \n");
    InitStack(s);
    
    printf("(2) 链栈 s 为 %s \n", StackEmpty(s) ? "空" : "非空");
    
    printf("(3) 依次进栈元素 a, b, c, d, e\n");
    Push(s, 'a');
    Push(s, 'b');
    Push(s, 'c');
    Push(s, 'd');
    Push(s, 'e');
    printf("(4) 链栈 s 为 %s \n", StackEmpty(s) ? "空" : "非空");
    
    printf("(5) 链栈的长度: %d \n", StackLength(s));
    
    printf("(6) 从栈顶到栈底的元素 :");
    DispStack(s);
    
    printf("(7) 出链栈序列: ");
    while ( ! StackEmpty(s) ) {
        Pop(s, e);
        printf(" %c" ,e);
    }
    printf("\n");
    

    printf("(8) 链栈 s 为 %s \n", StackEmpty(s) ? "空" : "非空");
    
    printf("释放链栈");
    ClearStack(s);
    return 0;
}
