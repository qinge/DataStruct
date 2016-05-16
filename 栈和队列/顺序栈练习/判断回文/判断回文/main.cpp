//
//  main.cpp
//  判断回文
//
//  Created by qinge on 16/5/16.
//  Copyright © 2016年 snqu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


#define MaxSize 100

typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;


extern void InitStack(SqStack * &s);
extern void ClearStack(SqStack * &s);
extern int StackLength(SqStack *s);
extern int StackEmepty(SqStack *s);
extern int Push(SqStack * &s, ElemType e);
extern int Pop(SqStack * &s, ElemType &e);
extern int GetTop(SqStack *s, ElemType &e);
extern void DispStack(SqStack *s);

int symmetry(ElemType str[]);

int main(int argc, const char * argv[]) {
    
    // char to string
    char tab[4];
    tab[0] = 'c';
    tab[1] = 'a';
    tab[2] = 't';
    tab[3] = '\0';
    string tmpS(tab);
    cout << tmpS << "\n";
    
    // string to char* - but thats not what I want
    
    char *c = const_cast<char*>(tmpS.c_str());
    cout << c << "\n";

    
    
    string tmp = "wow";
    ElemType str[12];
    strcpy(str, tmp.c_str());
    if (symmetry(str)) {
        printf("%s 是回文 \n", tmp.c_str());
    }else {
        printf("%s 不是回文 \n", tmp.c_str());
    }
    
    return 0;
}


/**
 *  判断是否是回文
     扫描字符串并依次入栈， 然后依次退栈 跟字符串对应位置对比
 *
 *  @param str str
 *
 *  @return
 */
int symmetry(ElemType str[]){
    int i;
    ElemType e;
    SqStack *st;
    InitStack(st);
    for (i = 0; str[i] != '\0'; i++) {
        Push(st, str[i]);   //  将 串中所有元素入栈
    }
    for (i = 0; str[i] != '\0'; i++) {
        Pop(st, e); // 退栈元素 e
        if (str[i] != e) {
            return 0;
        }
    }
    return 1;
}
