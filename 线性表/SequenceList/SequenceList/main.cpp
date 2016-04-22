//
//  main.cpp
//  SequenceList
//
//  Created by qinge on 16/4/22.
//  Copyright © 2016年 Q. All rights reserved.
//

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

int main(int argc, const char * argv[]) {
    
    SqList *L;
    ElemType e;
    printf("(1) 初始化顺序表L \n");
    InitList(L);
    
    printf("(2) 尾插法 插入 a,b,c,d,e 元素 \n");
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'e');
    
    printf("(3) 输出顺序表 \n");
    DispList(L);
    
    printf("(4) 顺序表 L 的长度 = %d \n",  ListLength(L));
    printf("(5) 顺序表 L 为 %s \n", (ListEmpty(L) ? "空" : "非空"));
    
    GetElem(L, 3, e);
    printf("(6) 顺序表 L 的第三个元素 = %c \n", e);
    
    printf("(7) 元素 a 的位置 = %d \n", LocateElem(L, 'a'));
    
    printf("(8) 在第四个位置插入元素 f \n");
    ListInsert(L, 4, 'f');
    printf("(9) 输出顺序表 \n");
    DispList(L);
    
    printf("(10) 删除 L 的第三个元素 \n");
    ListDelete(L, 3, e);
    printf("(11) 输出顺序表 \n");
    DispList(L);
    printf("e = %c \n", e);
    
    printf("(12) 释放顺序表 \n");
    DestroyList(L);
    printf("(13) 顺序表 L 为 %s \n", (ListEmpty(L) ? "空" : "非空"));
    
    return 0;
}
