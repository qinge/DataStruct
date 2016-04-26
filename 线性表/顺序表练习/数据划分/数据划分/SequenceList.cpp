//
//  SequenceList.cpp
//  SequenceList
//
//  Created by qinge on 16/4/22.
//  Copyright © 2016年 Q. All rights reserved.
//

#include "SequenceList.hpp"

// 导入该头文件 否则 malloc 函数报错
#include <stdlib.h>

#define MaxSize 50

typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
    
}SqList;


/**
 *  使用数组创建顺序表
 *
 *  @param L L
 *  @param a ElemType a[]
 *  @param n a.length
 */
void CreateList(SqList * &L, ElemType a[], int n) {
    int i;
    L = (SqList *)malloc(sizeof(SqList));
    for (i = 0; i < n; i++) {
        L -> data[i] = a[i];
    }
    L -> length = n;
}


/**
 *  初始化顺序表
 *
 *  @param L
 */
void InitList(SqList * &L) {
    L = (SqList *) malloc(sizeof(SqList));
    L -> length = 0;
}

/**
 *  释放顺序表
 *
 *  @param L
 */
void DestroyList(SqList * &L) {
    free(L);
}

/**
 *  顺序表判空
 *
 *  @param L
 *
 *  @return L -> length == 0
 */
int ListEmpty(SqList *L) {
    return L -> length == 0;
}

/**
 *  顺序表 L 元素个数
 *
 *  @param L
 *
 *  @return L -> length
 */
int ListLength(SqList *L) {
    return L -> length;
}

/**
 *  输出顺序表
 *
 *  @param L
 */
void DispList(SqList *L) {
    int i;
    if (ListEmpty(L)) {
        return;
    }
    for (i = 0; i < L -> length; i++) {
        printf(" %d", L -> data[i]);
    }
    printf("\n");
}

/**
 *  获取顺序表 L 中 第 i 个元素
 *
 *  @param L 顺序表
 *  @param i 第 i 个元素  因为顺序表下标从 1 开始
 *  @param e 填入 e
 *
 *  @return 0: 失败 , 1: 成功
 */
int GetElem(SqList *L, int i, ElemType &e){
    if (L -> length == 0 || i < 1 || i > L -> length) {
        return  0;
    }
    
    e = L -> data[i - 1];
    
    return 1;
}


/**
 *  查找元素 e 的位置
 *
 *  @param L
 *  @param e
 *
 *  @return 0: 失败 , i: 位置
 */
int LocateElem(SqList *L, ElemType e){
    int i = 0;
    while (i < L -> length && L -> data[i] != e) {
        i++;
    }
    if (i > L -> length) {
        return 0;
    }else{
        return i + 1;
    }
}

/**
 *  L 中 第 i 个元素插入 e
 *
 *  @param L
 *  @param i
 *  @param e 
 *
 *  @return 0: 失败 , 1: 成功
 */
int ListInsert(SqList * &L, int i, ElemType e){
    int j;
    if (i < 1 || i > L -> length + 1) {
        return 0;
    }
    i --;
    for (j = L -> length; j > i; j--) {
        L -> data[j] = L -> data[j-1];
    }
    L -> data[i] = e;
    L -> length ++;
    return 1;
}



/**
 *  在顺序表 L 中删除第 i 个元素
 *
 *  @param L
 *  @param i
 *  @param e
 *
 *  @return 0: 失败 , 1: 成功
 */
int ListDelete(SqList * &L, int i, ElemType &e){
    if(i < 1 || i > L -> length){
        return 0;
    }
    
    i--;
    e = L -> data[i];
    
    for (int j = i; j < L -> length - 1; j++) {
        L -> data[j] = L -> data[j+1];
    }
    L -> length --;
    return 1;
}











