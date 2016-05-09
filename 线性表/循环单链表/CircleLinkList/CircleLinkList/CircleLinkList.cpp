//
//  CircleLinkList.cpp
//  CircleLinkList
//
//  Created by qinge on 16/5/4.
//  Copyright © 2016年 Q. All rights reserved.
//

#include "CircleLinkList.hpp"
#include <stdlib.h>

typedef char ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkList;


void InitList(LinkList * &L){
    L = (LinkList *)malloc(sizeof(LinkList));
    L -> next = L;
}


/**
 *  一个个往后指下去 一个个释放
 *
 *  @param L
 */
void DestoryList(LinkList * &L){
    LinkList *p = L, *q = p -> next;
    while (q != L) {    // 注意判断条件
        free(p);
        p = q;
        q = p -> next;
    }
    free(p);
}


int ListEmpty(LinkList * L){
    return (L -> next == L);
}



int ListLength(LinkList *L){
    LinkList *p = L;
    int i = 0;
    
    while (p -> next != L) {
        i++;
        p = p -> next;
    }
    return i;
}

void DispList(LinkList * L){
    LinkList *p = L -> next;
    while (p != L) {
        printf(" %c", p -> data);
        p = p -> next;
    }
    printf("\n");
}


int GetElem(LinkList * L, int i, ElemType &e){
    int j = 0;
    LinkList *p;
    if (L -> next != L) {
        // 非空
        if (i == 1) {
            e = L -> next -> data;
            return 1;
        }else{
            p = L -> next;
            while (j < i - 1 && p != L) {
                j++;
                p = p -> next;
            }
            if (p == L) {
                return 0;
            }else{
                e = p -> data;
                return 1;
            }
        }
        
        return 0;
    }else{
        return 0;   // 空表
    }
}

int LocateElem(LinkList * L, ElemType e){
    LinkList *p = L -> next;
    int n = 1;
    while (p != L && p -> data != e) {
        p = p -> next;
        n++;
    }
    if (p == L) {
        return 0;
    }else{
        return n;
    }
}


int ListInsert(LinkList * &L, int i, ElemType e){
    int j = 0;
    LinkList *p = L, *s;
    if (p -> next == L || i == 1) {
        s = (LinkList *)malloc(sizeof(LinkList));
        s -> data = e;
        s -> next = p -> next;
        p -> next = s;
        return 1;
    }else{
        p = L -> next;
        while (j < i -2 && p != L) {
            j++;
            p = p -> next;
        }
        if (p == L) {
            return 0;
        }else{
            s = (LinkList *)malloc(sizeof(LinkList));   //  找到 i - 1 个结点 *p
            s -> data = e;
            s -> next = p -> next;  // *s 插入到 *p 之后
            p -> next = s;
            return 1;
        }
    }
}


int ListDelete(LinkList * &L, int i, ElemType &e){
    int j = 0;
    LinkList *p = L, *q;
    if (p -> next != L) {
        if (i == 1) {
            q = L -> next;
            e = q -> data;
            L -> next = q -> next;
            free(q);
            return 1;
        }else{
            p = L -> next;
            while (j < i - 2 && p != L) {
                j++;
                p = p -> next;
            }
            if (p  == L) {
                return 0;   //   未找到第 i-1 个结点
            }else{
                q = p -> next;
                e = q -> data;
                p -> next = q -> next;
                free(q);
                return 1;
            }
            
        }
    }
    return 0;
}




