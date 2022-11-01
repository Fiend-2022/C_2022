#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;//定义结构体元素类型

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;				//定义结构体

//打印链表
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

//新增一个链表元素
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	if (*pphead == NULL)//无节点
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

//头删
void SLTPopFront(SLTNode** pphead)
{
	SLTNode* tmp = *pphead;
	*pphead = (*pphead)->next;
	free(tmp);

}

//尾删
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

//查找
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

//任意插
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	assert(*pphead);
	
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);//头插
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

//任意删
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)
	{
		SLTPopFront(pphead);//头删
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

	printf("第1次打印:\n");//1
	SLTPrint(s1);//1

	SLTPushBack(&s1, 1);
	SLTPushBack(&s1, 2);
	SLTPushBack(&s1, 2);
	SLTPushBack(&s1, 3);
	SLTPushBack(&s1, 2);
	SLTPushBack(&s1, 2);
	SLTInsert(&s1, SLTFind(s1, 2), 22);
	printf("第2次打印:\n");//2
	SLTPrint(s1);//2

	SLTErase(&s1, SLTFind(s1, 3));
	printf("第3次打印:\n");//3
	SLTPrint(s1);//3

	printf("%p \n__________\n", SLTFind(s1, 1));

	//查找多个相同元素的位置
	SLTNode* pos = SLTFind(s1, 2);
	int i = 1;
	while (pos)
	{
		printf("第%d个2的节点是：%p\n", i++, pos);
		pos = SLTFind(pos->next, 2);
	}



	return 0;
}