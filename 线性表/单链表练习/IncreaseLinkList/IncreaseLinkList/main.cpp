//
//  main.cpp
//  IncreaseLinkList
//
//  Created by qinge on 16/4/27.
//  Copyright © 2016年 Q. All rights reserved.
//

/**
 
 题目:
 
 带头结点单链表 L 设计算法使其元素递增有序排列
 
 */



#include <iostream>

typedef char ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkList;


extern void InitList(LinkList * &L);
extern void DestroyList(LinkList * &L);
extern void DispList(LinkList *L);

void CreateListR(LinkList * &L, ElemType a[], int n);
void sort(LinkList * &L);
void sort2(LinkList * &L);

int main(int argc, const char * argv[]) {
    LinkList *L;
    
    printf("(1) 尾插法建单链表 L \n");
    ElemType a[] = {'9', '2', '1', '7', '5', '3', '6', '4', '0', '8'};
    CreateListR(L, a, 10);
    
    printf("(2) 输出单链表 \n");
    DispList(L);

    printf("(3) 排序单链表\n");
    sort2(L);
    
    printf("(4) 输出单链表 \n");
    DispList(L);
    
    return 0;
}


/**
 *  排序单链表
 
    采用直接插入法排序: 先构造只有一个数据结点的有序表, 在有序表中通过比较找插入 *p 的直接前驱结点 *q, 然后*p 插入 *p 之后
 *
 *  @param L L
 */
void sort(LinkList * &L){
    LinkList *p = L -> next, *q, *r;
    
    if (p != NULL) {
        r = p -> next;
        p -> next = NULL;   //  创建只包含一个元素的链表
        p = r;
    }
    while (p != NULL) {
        r = p -> next;
        q = L;
        while (q -> next != NULL && q -> next -> data < p -> data) {
            q = q -> next; // 找需要插入 *p 的位置
        }
        p -> next = q -> next;  //  *p 插入 *q 之后
        q -> next = p;  //
        p = r;
    }
    
}


/**
 *  自己回想理解下在来一遍
 *
 *  @param L
 */
void sort2(LinkList * &L){
    LinkList *p = L -> next, *q, *r;
    if (p != NULL) {
        r = p -> next;
        p -> next = NULL;
        p = r; // 到这里后 L 里面只有第一个结点元素了  p 指向第二个结点
        
        while (p != NULL) {
            r = p -> next; // 依次取结点出来与 L 中的排序好的结点比较 找到插入位置
            q = L; //此处不能是 q = L -> next; 因为下面 while 里面要用到 q -> next;
            
            while (q -> next != NULL && q -> next -> data < p -> data) {
                q = q -> next;
            }
            
            p -> next = q -> next;
            q -> next = p;
            
            p = r;
        }
    }
}














