//
//  main.cpp
//  ReverseDLinkList
//
//  Created by qinge on 16/5/3.
//  Copyright © 2016年 Q. All rights reserved.
//
/**
 
 有一个带头的双链表 L, 设计一个算法将其所有元素逆置， 即第一个元素变为最后一个 第二个变为 倒数第二个，最后一个变为第一个
 
 
 */

#include <iostream>

typedef char ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkList;


extern void DestroyList(DLinkList * &L);
extern void DispList(DLinkList *L);

void CreateListR(DLinkList * &L, ElemType a[], int n);
void ReverseDLinkList(DLinkList * &L);

int main(int argc, const char * argv[]) {
    DLinkList *L;
    ElemType a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int n = 10;
    CreateListR(L, a, n);
    printf("(1) 交换前输出链表 \n");
    DispList(L);
    
    ReverseDLinkList(L);
    
    printf("(2) 交换后输出链表 \n");
    DispList(L);
    
    return 0;
}



/**
 *  先构造只有一个头结点的双链表 L (利用原来头结点)， 用 p 扫描双链表所有结点，采用头插法将 *p 结点插入到 L 中
 *
 *  @param L
 */
void ReverseDLinkList(DLinkList * &L){
    DLinkList *p = L -> next, *q;
    L -> next = NULL;
    while (p != NULL) {
        q = p -> next; // 1
        p -> next = L -> next;  //  头插法 *p 插入 L 中
        if (L -> next != NULL) {
            L -> next -> prior = p;
        }
        L -> next = p;
        p -> prior = L;
        p = q;
    }
    
}



