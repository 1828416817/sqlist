#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"
//#include "Seqlist.cpp"

int main()
{
	SqList A, B, C; int n;

	SL_Initiate(A); SL_Initiate(B); SL_Initiate(C);

	scanf_s("%d", &n);//����A���Ԫ�ظ���
	SL_Create(A, n);

	scanf_s("%d", &n);//����B���Ԫ�ظ���
	SL_Create(B, n);

	MergeList_Sq(A, B, C); //�ϲ�

	SL_Print(C);
	SL_Free(A); SL_Free(B); SL_Free(C);
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

void MergeList_Sq(SqList LA, SqList LB, SqList& LC)
//��֪˳���LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
//�鲢LA��LB�õ��µ�˳���LC��LC��Ԫ��Ҳ��ֵ�ǵݼ����С�
{
	// �������ﲹ����룬��ɱ�������
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


