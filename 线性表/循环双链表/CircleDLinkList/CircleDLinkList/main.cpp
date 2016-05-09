//
//  main.cpp
//  CircleDLinkList
//
//  Created by qinge on 16/5/9.
//  Copyright © 2016年 Q. All rights reserved.
//

#include <iostream>

typedef char ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkList;


extern void InitList(DLinkList * &L);
extern void DestroyList(DLinkList * &L);
extern int ListEmpty(DLinkList *L);
extern int ListLength(DLinkList *L);
extern void DispList(DLinkList *L);
extern int GetElem(DLinkList * L, int i, ElemType &e);
extern int LocateElem(DLinkList *L, ElemType e);
extern int ListInsert(DLinkList * &L, int i, ElemType e);
extern int ListDelete(DLinkList * &L, int i, ElemType &e);



int main(int argc, const char * argv[]) {

    DLinkList *L;
    ElemType e;
    printf("(1) 初始化循环单链表 \n");
    InitList(L);
    printf("(2) 依次采用尾插法插入 a,b,c,d,e 元素\n");
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'e');
    printf("(3) 输出循环单链表 \n");
    DispList(L);
    
    printf("(4) 输出循环单链表的长度 = %d \n", ListLength(L));
    
    printf("(5) 循环单链表为: %s \n", ListEmpty(L) ? "空" : "非空");
    
    GetElem(L, 3, e);
    printf("(6) 循环单链表的第三个元素 = %c \n", e);
    
    printf("(7) 元素 a 的位置 = %d \n", LocateElem(L, 'a'));
    
    printf("(8) 在第四个位置上插入 f 元素\n");
    ListInsert(L, 4, 'f');
    printf("(9) 输出循环单链表 \n");
    DispList(L);
    
    printf("(10) 删除 L 的第三个元素 \n");
    ListDelete(L, 3, e);
    printf("(11) 输出循环单链表 \n");
    DispList(L);
    
    printf("(12) 释放循环单链表 \n");
    DestroyList(L);

    
    return 0;
}
