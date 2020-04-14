#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"
//#include "Seqlist.cpp"

int main()
{
	SqList A, B, C; int n;

	SL_Initiate(A); SL_Initiate(B); SL_Initiate(C);

	scanf_s("%d", &n);//输入A表的元素个数
	SL_Create(A, n);

	scanf_s("%d", &n);//输入B表的元素个数
	SL_Create(B, n);

	MergeList_Sq(A, B, C); //合并

	SL_Print(C);
	SL_Free(A); SL_Free(B); SL_Free(C);
}

void SL_Initiate(SqList& L)
// 顺序表的初始化，即构造一个空的顺序表
{
	L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L.length = 0;
}

void SL_Free(SqList& L)
// 释放顺序表
{
	free(L.elem);
}

bool SL_IsEmpty(SqList L)
// 判断顺序表是否空
{
	return L.length == 0;
}

bool SL_IsFull(SqList L)
// 判断顺序表是否满
{
	return L.length == MAXSIZE;
}

void SL_Create(SqList& L, int n)
// 输入n个数据元素，创建一个顺序表L
{
	int i;
	L.length = n;
	for (i = 0; i < n; i++)
		scanf_s("%d", &L.elem[i]);
}

void SL_Print(SqList L)
// 输出整个顺序表
{
	if (L.length == 0)
	{
		printf("The slist is empty.\n");
		return;
	}

	for (int i = 0; i < L.length; i++)
		printf("%d  ", L.elem[i]);
	printf("\n");
}

void MergeList_Sq(SqList LA, SqList LB, SqList& LC)
//已知顺序表LA和LB的元素按值非递减排列
//归并LA和LB得到新的顺序表LC，LC的元素也按值非递减排列。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	int i, j, k;
	i = j = 0;
	LC.length = LA.length + LB.length;
	for (k = 0; k <= LC.length; k++)
	{

		if (i == LA.length)
		{
			LC.elem[k] = LB.elem[j++];
			continue;
		}
		if (j ==LB.length)
		{
			LC.elem[k] = LA.elem[i++];
			continue;
		}

		if (LA.elem[i] < LB.elem[j])
		{
			LC.elem[k] = LA.elem[i++];
		}

		else
		{
			LC.elem[k] = LB.elem[j++];
		}
	}

	
}


