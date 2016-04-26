//
//  main.cpp
//  SplitLinkList
//
//  Created by qinge on 16/4/26.
//  Copyright © 2016年 Q. All rights reserved.
//

/**
 
 题目:
 带头结点单链表 L = {a1, b1, a2, b2, ... an, bn} 设计算法将其拆分为 L1 和 L2，
 L1 = {a1, a2, ... an}, L2 = {bn, bn-1, ... b2,b1}, 要求 L1 使用 L 的头结点
 
 
 
 */

#include <iostream>

typedef char ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkList;


extern void InitList(LinkList * &L);
extern void DestroyList(LinkList * &L);
extern int ListEmpty(LinkList *L);
extern int ListLength(LinkList *L);
extern void DispList(LinkList *L);
extern int GetElem(LinkList *L, int i, ElemType &e);
extern int LocateElem(LinkList *L, ElemType e);
extern int ListInsert(LinkList * &L, int i, ElemType e);
extern int ListDelete(LinkList * &L, int i, ElemType &e);

void CreateListR(LinkList * &L, ElemType a[], int n);


void SpList(LinkList *&L, LinkList * &L1, LinkList * &L2);


int main(int argc, const char * argv[]) {
    
    LinkList *L, *L1, *L2;
    
    printf("(1) 尾插法建单链表 L \n");
    ElemType a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    CreateListR(L, a, 10);
    
    printf("(2) 输出单链表 \n");
    DispList(L);
    
    
    printf("(3) 拆分单链表 L 为 L1, L2 \n");
    
    SpList(L, L1, L2);
    printf("(4) 输出单链表 L1 = ");
    DispList(L1);
    printf("\n");

    
    printf("(5) 输出单链表 L2 = ");
    DispList(L2);
    printf("\n");
    
    DestroyList(L);
//    DestroyList(L1);  // 因为 L1 没有使用 malloc 初始化(不确定这个解释正确)
    DestroyList(L2);
    
    return 0;
}


/**
 *  
 拆分 L 为 L1 L2, L1 使用L的头结点
 L = {a1, b1, a2, b2, ... an, bn}
 L1 = {a1, a2, ... an}
 L2 = L2 = {bn, bn-1, ... b2,b1}
 
 *
 *  @param L
 *  @param L1
 *  @param L2
 */
void SpList(LinkList *&L, LinkList * &L1, LinkList * &L2){
    LinkList *p = L -> next, *q, *r; // p 指向第一个数据结点
    L1 = L; //  L1 利用原来 L 的头结点
    r = L1; //  r 始终指向 L 的尾结点
    
    L2 = (LinkList *)malloc(sizeof(LinkList));
    L2 -> next = NULL;
    
    while (p != NULL) {
        q = p -> next;  //  1. q 先记录 p -> next
        
        r -> next = p;  // 2. 尾插法 建立 L1
        r = p;
        
        p = q -> next;  // 3. 为何不是 p = p -> next 呢 因为 1 中 要 q 赋值时候需要 p 不能指向下一个
        
        q -> next = L2 -> next; // 4. 头插法建立 L2
        L2 -> next = q;
    }
    
    r -> next = NULL;   // 5. 尾插法最后一个元素 next 指向 NULL (容易忘记)
    
}







