#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"


int main()
{
	SqList L; int n, i, x, element, location;

	SL_Initiate(L);

	scanf_s("%d", &n);//����Ԫ�صĸ���
	SL_Create(L, n);

	scanf_s("%d", &i);//�������ȡԪ�ص�λ��
	SL_GetAt(L, i, element);

	scanf_s("%d", &x);//���������Ԫ�ص�ֵ
	location = SL_FindValue(L, x);

	printf("%d\n%d\n", element, location);

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

void SL_GetAt(SqList L, int i, ElemType& e)
// ��ȡ˳���L�ĵ�i��Ԫ�ظ���e��i����Ч��Χ[1,L.length]��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/

	if (i<1 || i>L.length)
	{
		return;
	}
	e = L.elem[i - 1];


	/********** End **********/
}

int SL_FindValue(SqList L, ElemType x)
// ��˳���L�в��ҵ�һ��ֵΪx��Ԫ�أ��ҵ��򷵻ظ�Ԫ���ڱ��е�λ�ã����򷵻�0��
{
	// �������ﲹ����룬��ɱ�������
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


