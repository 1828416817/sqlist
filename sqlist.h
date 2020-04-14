#pragma once
/*************************************************************
    顺序表的合并  头文件
**************************************************************/

#define  MAXSIZE 100     //最大长度
typedef int ElemType;
typedef  struct {
    ElemType* elem;     //指向数据元素的起始地址
    int  length;          //线性表的当前长度                                                      
}SqList;

// 顺序表的初始化，即构造一个空的顺序表
void SL_Initiate(SqList& L);

// 释放顺序表
void SL_Free(SqList& L);

// 判断顺序表是否空
bool SL_IsEmpty(SqList L);

// 判断顺序表是否满
bool SL_IsFull(SqList L);

// 输入n个数据元素，创建一个顺序表L
void SL_Create(SqList& L, int n);

// 输出整个顺序表
void SL_Print(SqList L);

//已知顺序表LA和LB的元素按值非递减排列
//归并LA和LB得到新的顺序表LC，LC的元素也按值非递减排列。
void MergeList_Sq(SqList LA, SqList LB, SqList& LC);

