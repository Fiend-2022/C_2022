#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;//����ṹ��Ԫ������

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;				//����ṹ��

//��ӡ����
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d-", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//����һ������Ԫ��
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	if (*pphead == NULL)//�޽ڵ�
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

//ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	SLTNode* tmp = *pphead;
	*pphead = (*pphead)->next;
	free(tmp);

}

//βɾ
void SLTPopBack(SLTNode** pphead)
{
	if (NULL == *pphead)
	{
		printf("ERROR:SLinkList is NULL\n");
	}
	else
	{
		SLTNode* cur = *pphead;
		SLTNode* tail = *pphead;
		while (cur->next != NULL)
		{
			tail = cur;
			cur = cur->next;
		}
		tail->next = NULL;
		free(cur);
	}
}

//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//�����
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	assert(*pphead);
	
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);//ͷ��
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuySLTNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

//����ɾ
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)
	{
		SLTPopFront(pphead);//ͷɾ
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

int main()
{
	SLTNode* s1 = NULL;

	SLTPushFront(&s1, 10);

	printf("��1�δ�ӡ:\n");//1
	SLTPrint(s1);//1

	SLTPushBack(&s1, 1);
	SLTPushBack(&s1, 2);
	SLTPushBack(&s1, 2);
	SLTPushBack(&s1, 3);
	SLTPushBack(&s1, 2);
	SLTPushBack(&s1, 2);
	SLTInsert(&s1, SLTFind(s1, 2), 22);
	printf("��2�δ�ӡ:\n");//2
	SLTPrint(s1);//2

	SLTErase(&s1, SLTFind(s1, 3));
	printf("��3�δ�ӡ:\n");//3
	SLTPrint(s1);//3

	printf("%p \n__________\n", SLTFind(s1, 1));

	//���Ҷ����ͬԪ�ص�λ��
	SLTNode* pos = SLTFind(s1, 2);
	int i = 1;
	while (pos)
	{
		printf("��%d��2�Ľڵ��ǣ�%p\n", i++, pos);
		pos = SLTFind(pos->next, 2);
	}



	return 0;
}