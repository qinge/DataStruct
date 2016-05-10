//
//  CircleDLinkList.cpp
//  CircleDLinkList
//
//  Created by qinge on 16/5/9.
//  Copyright © 2016年 Q. All rights reserved.
//

#include "CircleDLinkList.hpp"
#include <stdlib.h>

typedef char ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkList;


void InitList(DLinkList * &L){
    L = (DLinkList *)malloc(sizeof(DLinkList));
    L -> prior = L -> next = L;
}

void DestroyList(DLinkList * &L){
    DLinkList *p = L, *q = p -> next;
    while ( q != L ) {
        free(p);
        p = q;
        q = p -> next;
    }
    free(p);
}

int ListEmpty(DLinkList *L){
    return L -> next == L;
}

int ListLength(DLinkList *L){
    DLinkList *p = L;
    int i = 0;
    while (p -> next != L) {
        i++;
        p = p -> next;
    }
    return i;
}


void DispList(DLinkList *L){
    DLinkList *p = L -> next;
    while (p != L) {
        printf(" %c", p -> data);
        p = p -> next;
    }
    printf("\n");
}

int GetElem(DLinkList * L, int i, ElemType &e){
    int j = 0;
    DLinkList *p;
    if (L -> next != L) {
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
    }else {
        return 0;
    }
}



int LocateElem(DLinkList *L, ElemType e){
    int n = 1;
    DLinkList *p = L -> next;
    while (p != NULL && p -> data != e) {
        n++;
        p = p -> next;
    }
    if (p == NULL) {
        return 0;
    }else{
        return n;
    }
}


int ListInsert(DLinkList * &L, int i, ElemType e){
    int j = 0;
    DLinkList *p = L, *s;
    if (p -> next == L) {   //   空表时候
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s -> data = e;
        p -> next = s; s-> next = p;
        p -> prior = s; s -> prior = p;
        return 1;
    }else if (i == 1){  // 插入到表头的时候
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s -> data = e;
        s -> next = p -> next; p -> next = s;
        s -> next -> prior = s; s -> prior = p;
        return 1;
    }else{
        p = L -> next;
        while ( j < i - 2 && p != L ) {
            j++;
            p = p -> next;
        }
        if (p == L) {
            return 0;
        }else {
            s = (DLinkList *)malloc(sizeof(DLinkList));
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
}


int ListDelete(DLinkList * &L, int i, ElemType &e){
    int j = 0;
    DLinkList *p = L, *q;
    if (p -> next != L) {
        if (i == 1) {
            q = L -> next;
            e = q -> data;
            L -> next = q -> next;
            q -> next -> prior = L;
            free(q);
            return 1;
        }else{
            p = L -> next;
            while (j < i - 2 && p != NULL) {
                j++;
                p = p -> next;
            }
            if (p == NULL) {    //  未找到 i - 1 个结点
                return 0;
            }else{
                q = p -> next;
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
    }else{
        return 0;
    }
}







