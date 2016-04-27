//
//  LinkList.cpp
//  LinkList
//
//  Created by qinge on 16/4/25.
//  Copyright © 2016年 Q. All rights reserved.
//


#include <stdlib.h>
#include "LinkList.hpp"

typedef char ElemType;

/**
 *  单链表
 */
typedef struct LNode{
    ElemType data;
    struct LNode *next;
    
}LinkList;


/**
 *  双链表
 */
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkList;



/**
 *  头插法建立单链表
     生成次序跟数组顺序相反
 1. 创建 L, L -> next = NULL;
 2. 创建结点 s 并赋值
 3. s 结点插入开始结点之前 头结点后
 4. 重置头结点
 
 *
 *  @param L
 *  @param a
 *  @param n
 */
void CreateListF(LinkList * &L, ElemType a[], int n){
    
    LinkList *s;
    int i;
    L = (LinkList *)malloc(sizeof(LinkList)); // 创建头结点
    L -> next = NULL;
    
    for (i = 0; i < n; i++) {
        s = (LinkList *)malloc(sizeof(LinkList)); // 创建结点
        s -> data = a[i];
        s -> next = L -> next;  // *s 插入到开始节点之前, 头结点之后
        L -> next = s;
    }
    
}


/**
 *  尾插法建立单链表
 
 1. r 指向头结点
 2. 创建 s 结点设置值
 3. r -> next 指向新创建的结点
 4. r = s 循环时候始终 r 指向尾结点
 5. r -> next = NULL;
 
 *
 *  @param L
 *  @param a
 *  @param n
 */
void CreateListR(LinkList * &L, ElemType a[], int n){
    LinkList *s, *r;
    int i;
    L = (LinkList *)malloc(sizeof(LinkList)); // 创建头结点
    L -> next = NULL;
    r = L;  // r 首先指向头结点
    
    for (i = 0; i < n; i++) {
        s = (LinkList *)malloc(sizeof(LinkList)); // 创建结点
        s -> data = a[i];
        s -> next = NULL;
        
        r -> next = s;  // r 始终指向尾节点
        r = s;
        
    }
    r -> next = NULL;
    
}


/**
 *  初始化链表
 *
 *  @param L
 */
void InitList(LinkList * &L){
    L = (LinkList *)malloc(sizeof(LinkList));
    L -> next = NULL;
}


/**
 *  销毁链表
 *  需要释放每一个结点
 *  @param L L
 */
void DestroyList(LinkList * &L){
    LinkList *p = L, *q = p -> next;
    while (q != NULL) {
        free(p);
        p = q;
        q = p -> next;
    }
    free(p);
}

/**
 *  链表判空
 *
 *  @param L
 *
 *  @return L -> next == NULL
 */
int ListEmpty(LinkList *L){
    return L -> next == NULL;
}

/**
 *  计算链表长度
 *
 *  @param L L
 *
 *  @return length
 */
int ListLength(LinkList *L){
    LinkList *p = L;
    int n = 0;
    while (p -> next != NULL) {
        n++;
        p = p -> next;
    }
    return n;
}


/**
 *  输出链表
 *
 *  @param L L
 */
void DispList(LinkList *L){
    LinkList *p = L -> next;
    while (p != NULL) {
        printf(" %c", p -> data);
        p = p -> next;
    }
    printf("\n");
}


/**
 *  获取链表第 i 个元素 填充到 e 中
 *
 *  @param L
 *  @param i
 *  @param e
 *
 *  @return 0: 失败 1: 成功
 */
int GetElem(LinkList *L, int i, ElemType &e){
    int j = 0;
    LinkList *p = L;
    while (j < i && p -> next != NULL) {
        j++;
        p = p -> next;
    }
    if (p == NULL) {
        return 0;
    }else {
        e = p -> data;
        return 1;
    }
}


/**
 *  查找结点 index
 *
 *  @param L
 *  @param e
 *
 *  @return 0: 失败, i: 成功返回 index
 */
int LocateElem(LinkList *L, ElemType e){
    LinkList *p = L -> next;
    int i = 1;
    
    while (p != NULL && p -> data != e) {
        i++;
        p = p -> next;
    }
    if (p == NULL) {
        return 0;
    }else{
        return i;
    }
}


/**
 *  尾插法 插入元素
 *
 *  @param L
 *  @param i
 *  @param e
 *
 *  @return 0: 失败, i: 成功返回 index
 */
int ListInsert(LinkList * &L, int i, ElemType e){
    LinkList *p = L, *s;
    int j = 0;
    
    while (j < i - 1 && p != NULL) {
        j++;
        p = p -> next;
    }
    
    if (p == NULL) {
        return 0;
    }else{
        s = (LinkList *)malloc(sizeof(LinkList));
        s -> data = e;
        
        s -> next = p -> next;
        p -> next = s;
        return 1;
    }

}


/**
 *  删除指定索引结点
 *
 *  @param L
 *  @param i
 *  @param e 
 *
 *  @return 0: 失败, i: 成功返回 index
 */
int ListDelete(LinkList * &L, int i, ElemType &e){
    LinkList *p = L, *q;
    int j = 0;
    while (j < i - 1 && p != NULL) {
        j++;
        p = p -> next;
    }
    if (p == NULL) {
        return 0;
    }else{
        q = p -> next; // 找到需要删除的结点
        if (q == NULL) {
            return 0;
        }
        e = q -> data;
        p -> next = q -> next;
        free(q);
        return 1;

    }
}






















