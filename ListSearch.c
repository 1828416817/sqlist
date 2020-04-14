#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"


int main()
{
	SqList L; int n, i, x, element, location;

	SL_Initiate(L);

	scanf_s("%d", &n);//输入元素的个数
	SL_Create(L, n);

	scanf_s("%d", &i);//输入待获取元素的位置
	SL_GetAt(L, i, element);

	scanf_s("%d", &x);//输入待查找元素的值
	location = SL_FindValue(L, x);

	printf("%d\n%d\n", element, location);

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

void SL_GetAt(SqList L, int i, ElemType& e)
// 获取顺序表L的第i个元素赋给e，i的有效范围[1,L.length]。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/

	if (i<1 || i>L.length)
	{
		return;
	}
	e = L.elem[i - 1];


	/********** End **********/
}

int SL_FindValue(SqList L, ElemType x)
// 在顺序表L中查找第一个值为x的元素，找到则返回该元素在表中的位置，否则返回0。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == x)
		{
			return i + 1;
		}
		return 0;
	}

	/********** End **********/
}


