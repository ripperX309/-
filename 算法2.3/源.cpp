#include <stdio.h>
#include <malloc.h>
#include <process.h>//exit()
#define OK 1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
#define LIST_INIT_SIZE 10
typedef struct
{
	ElemType*elem;
	int length;
	int listsize;
}SqList;
Status InitList(SqList &L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
Status ListTraverse(SqList L)
{
	ElemType*p;
	int i;
	p = L.elem;
	printf("线性表当前容量为: %d", L.listsize);
	if (L.length>0)
	{
		printf("线性表中有 %d 个元素,分别是:", L.length);
		for (i = 1; i <= L.length; i++)
			printf("%d", *p++);
	}
	else
		printf("目前还是空线性表");
	printf("\n");
	return OK;
}
int main()
{
	SqList La;
	Status i;
	i = InitList(La);
	ListTraverse(La);
	getchar();
	return 0;
}
