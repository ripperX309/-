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
	printf("���Ա�ǰ����Ϊ: %d", L.listsize);
	if (L.length>0)
	{
		printf("���Ա����� %d ��Ԫ��,�ֱ���:", L.length);
		for (i = 1; i <= L.length; i++)
			printf("%d", *p++);
	}
	else
		printf("Ŀǰ���ǿ����Ա�");
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
