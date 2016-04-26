//
//  main.cpp
//  数据划分
//
//  Created by qinge on 16/4/23.
//  Copyright © 2016年 Q. All rights reserved.
//

/**
 
 题目:
 
 顺序表 L 元素类型 ElemType 为整型 所有元素都不等， 以第一个元素分界，小于它的拍到他的前面，
 大于它的排它后面
 
 */

#include <iostream>

#define MaxSize 50

typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
    
}SqList;


extern void DestroyList(SqList * &L);
extern void DispList(SqList *L);
extern void CreateList(SqList * &L, ElemType a[], int n);
void move1(SqList *&L);
void move2(SqList *&L);

int main(int argc, const char * argv[]) {

    
    
    SqList *L;
    ElemType a[] = {3,5,6,1,4,2,7,9,8,0};
    
    printf("(1) 使用数组初始化顺序表 \n");
    CreateList(L, a, 10);
    
    printf("(2) 输出顺序表 \n");
    DispList(L);
    
    
    printf("(3) 顺序表开始以第一个元素分块\n");
    
//    move1(L);
    move2(L);
    
    printf("(4) 输出顺序表 \n");
    DispList(L);
    
    DestroyList(L);
    
    return 0;
}


/**
 *  
 题目:
 
 顺序表 L 元素类型 ElemType 为整型 所有元素都不等， 以第一个元素分界，小于它的拍到他的前面，
 大于它的排它后面
 
 解法 一:
 1. pivot 存放 data[0], int i = 0,j = L -> length - 1;
 2. 当 i != j 时循环
 3. 从 右 向左扫描, 找到一个小于 pivot 的 data[j] (注意: 需要先从右边开始扫描)
 4. 然后 从左向右扫描, 找到一个大于 pivot 的 data[i]
 5. 交换 data[j], data[i]
 
 *
 *  @param L
 */
void move1(SqList *&L){
    int i = 0, j = L -> length - 1;
    ElemType temp;
    ElemType pivot = L -> data[0];
    
    while (i != j) {
        // 条件不满足 改变index
        while (j > i && L -> data[j] > pivot) {
            j--;
        }
        while (i < j && L -> data[i] < pivot) {
            i++;
        }
        
        // 找到交换点
        if (i < j) {
            temp = L -> data[i];
            L -> data[i] = L -> data[j];
            L -> data[j] = temp;
        }
        
    }
}

/**
 *  
 划分方法2 思路跟一差不多 没有临时 temp， 从右边 data[j] 填充 data[i] 后 又从左边扫描 data[i] 填充 data[j]
  最后 i, j 指向同一个元素时候即为 pivot 的位置
 
 1. 以data[0] 为基准
 2. 从顺序表两端向中间扫描 直到 i = j
 3. 从右边向左扫描，找到小于 pivot 的 data[j] 放入 data[i] 
 4. 从左向右扫描 找到大于 pivot 的 data[i] 放入 data[j]
 5. i, j 指向同一个元素时候即为 pivot 的位置
 
 *
 *  @param L L
 */
void move2(SqList * &L){
    int i = 0, j = L -> length - 1;
    ElemType pivot = L -> data[0];
    while (i != j) {
        while (j > i && L -> data[j] > pivot) {
            j--;
        }
        L -> data[i] = L -> data[j];
        
        while (i < j && L -> data[i] < pivot) {
            i++;
        }
        L -> data[j] = L -> data[i];
    }
    L -> data[i] = pivot;
}















