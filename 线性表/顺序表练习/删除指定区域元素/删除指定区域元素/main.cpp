//
//  main.cpp
//  删除指定区域元素
//
//  Created by qinge on 16/4/23.
//  Copyright © 2016年 Q. All rights reserved.
//

/**
 
 
 有一个顺序表 A 设计一个算法 删除所有在 [x,y] 之间的所有元素， 要求时间 O(n), 空间 O(1)
 
 
 */

#include <iostream>

#define MaxSize 50

typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
    
}SqList;


extern void InitList(SqList * &L);
extern void DestroyList(SqList * &L);
extern int ListEmpty(SqList *L);
extern int ListLength(SqList *L);
extern void DispList(SqList *L);
extern int GetElem(SqList *L, int i, ElemType &e);
extern int LocateElem(SqList *L, ElemType e);
extern int ListInsert(SqList * &L, int i, ElemType e);
extern int ListDelete(SqList * &L, int i, ElemType &e);

void delelem(SqList *&L, ElemType x, ElemType y);

int main(int argc, const char * argv[]) {
    
    SqList *L;
    
    printf("(1) 初始化顺序表 \n");
    InitList(L);
    
    printf("(2) 插入元素 a,b,c,d,e,f \n");
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'e');
    
    printf("(3) 输出顺序表 \n");
    DispList(L);
    
    printf("(4) 删除指定区域元素 \n");
    
    // 删除指定区域元素
    delelem(L, 'b', 'd');
    
    printf("(5) 输出删除指定区域元素后的顺序表 \n");
    DispList(L);
    
    
    DestroyList(L);
    return 0;
}


/**
 *  删除指定区域元素
 
 *  从 i 开始扫描 L j 累计不满足条件元素 重建 L 只保留不满足元素 j
 *  只扫描一次 时间 O(n) , 两个临时变量 空间O(1)
 
 *
 *  @param L L
 *  @param x x
 *  @param y y
 */
void delelem(SqList *&L, ElemType x, ElemType y) {
    int i = 0, j = 0;
    while (i < L -> length) {
        if ( !(L -> data[i] >= x && L -> data[i] <= y) ) {
            L -> data[j] = L -> data[i];
            j++;
        }
        i++;
    }
    L -> length = j;
}

















