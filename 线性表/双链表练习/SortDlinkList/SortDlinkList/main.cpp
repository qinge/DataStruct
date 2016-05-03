//
//  main.cpp
//  SortDLinkList
//
//  Created by qinge on 16/5/3.
//  Copyright © 2016年 Q. All rights reserved.
//

/**
 题目:
 
 带头结点双链表 L, 设计算法使其元素有序递增排列
 
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
void SortDLinkList(DLinkList * &L);

int main(int argc, const char * argv[]) {
    DLinkList *L;
    ElemType a[] = {'2', '3', '4', '0', '7', '8', '1', '5', '6', '9'};
    int n = 10;
    CreateListR(L, a, n);
    printf("(1) 排序前输出链表 \n");
    DispList(L);
    
    SortDLinkList(L);
    
    printf("(2) 排序后输出链表 \n");
    DispList(L);
    
    return 0;
}


/**
 *  快速插入 只有一个结点肯定有序 查找需要插入的位置插入结点
 *
 *  @param L
 */
void SortDLinkList(DLinkList * &L){
    DLinkList *p = L -> next, *q, *r;
    if (p != NULL) {
        r = p -> next;
        p -> next = NULL; // 构建只含有一个结点的有序表 L
        p = r;
        
        while (p != NULL) {
            r = p -> next;
            q = L;
            while (q -> next != NULL && q -> next -> data < p -> data) {
                q = q -> next;  //  找到要插入 *p 的 直接前驱结点 *q
            }
            p -> next = q -> next;  //   *p 插入到 *q  之后
            if (q -> next != NULL) {
                q -> next -> prior = p;
            }
            q -> next = p;
            p -> prior = q;
            
            p = r;
        }
        
    }
}








