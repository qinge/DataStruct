//
//  DLinkList.cpp
//  DLinkList
//
//  Created by qinge on 16/4/26.
//  Copyright © 2016年 Q. All rights reserved.
//

#include "DLinkList.hpp"
#include <stdlib.h>

typedef char ElemType;

/**
 *  双链表
 */
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkList;


/**
 *  头插法建立双链表
 *
 *  @param L
 *  @param a
 *  @param n
 */
void CreateListF(DLinkList * &L, ElemType a[], int n){
    DLinkList *s;
    int i;
    L = (DLinkList *)malloc(sizeof(DLinkList));
    L -> prior = L -> next = NULL;
    for (i = 0; i < n; i++) {
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s -> data = a[i];
        s -> next = L -> next;
        if (L -> next != NULL) {
            L -> next -> prior = s;
        }
        
        L -> next = s;
        s -> prior = L;
    }
}


/**
 *  尾插法建立双链表
 *
 *  @param L
 *  @param a
 *  @param n
 */
void CreateListR(DLinkList * &L, ElemType a[], int n){
    DLinkList *s, *r;
    int i;
    L = (DLinkList *)malloc(sizeof(DLinkList));
    L -> prior = L -> next = NULL;
    r = L;
    
    for (i = 0; i < n; i++) {
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s -> data = a[i];
        
        r -> next = s;
        s -> prior = r;
        
        r = s;
        
    }
    r -> next = NULL;
}



void InitList(DLinkList * &L){
    L = (DLinkList *)malloc(sizeof(DLinkList));
    L -> prior = L -> next = NULL;
}

void DestroyList(DLinkList * &L){
    DLinkList *p = L, *q = p -> next;
    while (q != NULL) {
        free(p);
        p = q;
        q = p -> next;
    }
    free(p);
}


int ListEmpty(DLinkList *L){
    return L -> next == NULL;
}


int ListLength(DLinkList *L){
    DLinkList *p = L;
    int i = 0;
    while (p -> next != NULL) {
        i++;
        p = p -> next;
    }
    return i;
}


void DispList(DLinkList *L){
    DLinkList *p = L -> next;
    
    while (p != NULL) {
        printf(" %c", p -> data);
        p = p -> next;
    }
    printf("\n");
}

int GetElem(DLinkList *L, int i, ElemType &e){
    int j = 0;
    DLinkList *p = L;
    while (j < i && p != NULL) {    //  获取元素需要先判断链表存在
        j++;
        p = p -> next;
    }
    if (p == NULL) {
        return 0;
    }else{
        e = p -> data;
        return 1;
    }
    
}


int LocateElem(DLinkList *L, ElemType e){
    int j = 0;
    DLinkList *p = L -> next;
    while (p != NULL && p -> data != e) {  // 因为需要访问 p -> data 所以需要先 p != NULL
        j++;
        p = p -> next;
    }
    if (p == NULL) {
        return 0;
    }else{
        return j + 1;
    }
}

int ListInsert(DLinkList * &L, int i, ElemType e){
    int j = 0;
    DLinkList *p = L, *s;
    
    while (j < i -1 && p != NULL) { // 找到 i - 1 个结点
        j++;
        p = p -> next;
    }
    if (p == NULL) {
        return 0;
    }else{
        s = (DLinkList *)malloc(sizeof(DLinkList)); // i-1 指向 p , s 插入到 p 之后
        s -> data = e;
        
        s -> next = p -> next;
        if (p -> next != NULL) {
            p -> next -> prior = s;
        }
        
        s -> prior = p;
        p -> next = s;
        
        return 1;
    }
    
}



int ListDelete(DLinkList * &L, int i, ElemType &e){
    int j = 0;
    DLinkList *p = L, *q;
    while (j < i -1 && p!= NULL) {
        j++;
        p = p -> next;
    }
    if (p == NULL) {
        return 0;
    }else{
        q = p -> next; // q 指向要删除的结点
        if (q == NULL) {
            return 0;
        }
        e = q -> data;
        
        p -> next = q -> next;
        
        if (p -> next != NULL) {
            p -> next -> prior = p;
        }
        free(q);
        
        return 1;
    }
}
















