#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"


int main()
{
	SqList L; int n, i, x;

	SL_Initiate(L);

	scanf_s("%d", &n);//输入元素的个数
	SL_Create(L, n);

	scanf_s("%d%d", &i, &x);//输入待插入的位置和待插入元素的值
	SL_InsAt(L, i, x);

	scanf_s("%d", &i);//输入待删除元素的位置
	SL_DelAt(L, i);

	scanf_s("%d", &x);//输入待删除元素的值
	SL_DelValue(L, x);

	SL_Print(L);
	SL_Free(L);
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

void SL_InsAt(SqList& L, int i, ElemType e)
// 在顺序表的第i个位置插入新元素e, 即在元素L.elem[i-1]之前插入
// i的有效范围[1,L.length+1]
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (i<1 || i>L.length+1)
	{
		return;
	}
	else if (L.length >= MAXSIZE)
	{
		return;
	}
	else
	{


		for (int j = L.length; j >= i; j--)
		
			L.elem[j] = L.elem[j - 1];

		
		L.elem[i - 1] = e;
		L.length++;
	}
	
}

void SL_DelAt(SqList& L, int i)
// 删除顺序表L的第i个元素
//i的有效范围[1,L.length]
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/

	int j;
	if (L.length <= 0)
	{
		return;
	}
	else if (i<1 || i>L.length)
	{
		return;
	}
	else
	{
		for (j = i; j <= L.length - 1; j++)
		
			L.elem[j-1] = L.elem[j];
			L.length = L.length - 1;

		
	}

	/********** End **********/
}

void SL_DelValue(SqList& L, ElemType x)
// 删除第一个值为x的元素
{
	int index;
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == x)
		{
			index = i + 1;
			break;
		}
		
	}
	SL_DelAt(L, index);

	/********** End **********/
}


