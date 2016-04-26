//
//  main.cpp
//  DDLinkList
//
//  Created by qinge on 16/4/26.
//  Copyright © 2016年 Q. All rights reserved.
//

#include <iostream>

typedef char ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode *next;
}DLinkList;


extern void InitList(DLinkList * &L);
extern void DestroyList(DLinkList * &L);
extern int ListEmpty(DLinkList *L);
extern int ListLength(DLinkList *L);
extern void DispList(DLinkList *L);
extern int GetElem(DLinkList *L, int i, ElemType &e);
extern int LocateElem(DLinkList *L, ElemType e);
extern int ListInsert(DLinkList * &L, int i, ElemType e);
extern int ListDelete(DLinkList * &L, int i, ElemType &e);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
