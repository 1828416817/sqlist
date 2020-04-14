#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"


int main()
{
	SqList L; int n, i, x;

	SL_Initiate(L);

	scanf_s("%d", &n);//����Ԫ�صĸ���
	SL_Create(L, n);

	scanf_s("%d%d", &i, &x);//����������λ�úʹ�����Ԫ�ص�ֵ
	SL_InsAt(L, i, x);

	scanf_s("%d", &i);//�����ɾ��Ԫ�ص�λ��
	SL_DelAt(L, i);

	scanf_s("%d", &x);//�����ɾ��Ԫ�ص�ֵ
	SL_DelValue(L, x);

	SL_Print(L);
	SL_Free(L);
}


void SL_Initiate(SqList& L)
// ˳���ĳ�ʼ����������һ���յ�˳���
{
	L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L.length = 0;
}

void SL_Free(SqList& L)
// �ͷ�˳���
{
	free(L.elem);
}

bool SL_IsEmpty(SqList L)
// �ж�˳����Ƿ��
{
	return L.length == 0;
}

bool SL_IsFull(SqList L)
// �ж�˳����Ƿ���
{
	return L.length == MAXSIZE;
}

void SL_Create(SqList& L, int n)
// ����n������Ԫ�أ�����һ��˳���L
{
	int i;
	L.length = n;
	for (i = 0; i < n; i++)
		scanf_s("%d", &L.elem[i]);
}

void SL_Print(SqList L)
// �������˳���
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
// ��˳���ĵ�i��λ�ò�����Ԫ��e, ����Ԫ��L.elem[i-1]֮ǰ����
// i����Ч��Χ[1,L.length+1]
{
	// �������ﲹ����룬��ɱ�������
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
// ɾ��˳���L�ĵ�i��Ԫ��
//i����Ч��Χ[1,L.length]
{
	// �������ﲹ����룬��ɱ�������
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
// ɾ����һ��ֵΪx��Ԫ��
{
	int index;
	// �������ﲹ����룬��ɱ�������
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


