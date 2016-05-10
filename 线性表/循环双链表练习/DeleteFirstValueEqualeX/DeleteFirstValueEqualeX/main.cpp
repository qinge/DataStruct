//
//  main.cpp
//  DeleteFirstValueEqualeX
//
//  Created by qinge on 16/5/10.
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

int deletem(DLinkList * &L, ElemType e);


int main(int argc, const char * argv[]) {

    DLinkList *L;
    printf("(1) 初始化循环双链表 \n");
    InitList(L);
    printf("(2) 依次采用尾插法插入 a,b,c,d,e 元素\n");
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'a');
    printf("(3) 输出循环双链表 \n");
    DispList(L);
    
    printf("(4) 删除 data = a 的第一个结点 \n");
    deletem(L, 'a');
    printf("(5) 输出循环双链表 \n");
    DispList(L);
    
    return 0;
}



/**
 *  删除第一个data 域为 x 的结点
 *
 *  @param L
 *  @param e
 *
 *  @return
 */
int deletem(DLinkList * &L, ElemType e){
    DLinkList *p = L -> next;
    while (p != L && p -> data != e) {
        p = p -> next;
    }
    if (p == L) {
        return 0;
    }
    p -> next -> prior = p -> prior;
    p -> prior -> next = p -> next;
    free(p);
    return 1;
}












