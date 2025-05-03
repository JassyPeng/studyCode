#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

//typedef int HPDataType;


////�ѽṹ�Ķ���
//typedef struct Heap
//{
//	HPDataType* _hp;//����--�洢����
//	int _size;
//	int _capacity;
//}Heap;

//void Swap(HPDataType* x, HPDataType* y)
//{
//	HPDataType tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void Print(Heap hp)
//{
//	for (int i = 0; i < hp._size; i++)
//		printf("%d ", hp._hp[i]);
//	printf("\n");
//}
////�ѽṹ�ĳ�ʼ��
//void HPInit(Heap* hp)
//{
//	if (hp == NULL)
//	{
//		printf("��ʼ��ʧ��!\n");
//		return;
//	}
//	hp->_hp = NULL;
//	hp->_size = 0;
//	hp->_capacity = 0;
//}
//
//void AdjustUp(HPDataType* hp, int child)
//{
//	//////���ϵ���
//	int parents = (child - 1) / 2;
//	while (child > 0)
//	{
//		//�����,������
//		if (hp[parents] < hp[child])
//		{
//			Swap(&hp[parents], &hp[child]);
//			child = parents;
//			parents = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void AdjustDown(HPDataType* hp, int sz,  int parents)
//{
//	int child = parents / 2 + 1;///�������ӱȽ�С
//	while (child < sz)
//	{
//		if ((child + 1 < sz) && hp[child] > hp[child + 1])
//			child++;
//		if (hp[parents] > hp[child])
//		{
//			Swap(&hp[parents], &hp[child]);
//			parents = child;
//			child = parents * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
////�Ѳ���Ԫ�� -- ����ɹ�����true,���򷵻�false
//bool HPInsert(Heap* hp, HPDataType val)
//{
//	if (hp == NULL)
//		return false;
//	//�˴��������
//	if (hp->_capacity == hp->_size)
//	{
//		int newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
//		HPDataType* tmp = (HPDataType*)realloc(hp->_hp, newCapacity * sizeof(HPDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc");
//		}
//		//���ݳɹ�
//		hp->_hp = tmp;
//		hp->_capacity = newCapacity;
//	}
//
//	//������Ԫ��
//	hp->_hp[hp->_size++] = val;
//
//	if (hp->_size == 1)
//		return true;
//
//	//�������Ԫ�����ϵ���
//	int child = hp->_size - 1;
//	AdjustUp(hp->_hp, child);
//	return true;
//}
//
//void HPPop(Heap* hp)
//{
//	assert(hp);
//	assert(hp->_size > 0);
//	//**ɾ���Ѷ�Ԫ��
//	//������βԪ��
//	Swap(&hp->_hp[0], &hp->_hp[hp->_size - 1]);
//	hp->_size--;
//	AdjustDown(hp->_hp, hp->_size, 0);
//}
//
//int main()
//{
//	Heap hp;//������
//	HPInit(&hp);//��ʼ����
//	HPInsert(&hp, 1);//��������
//	HPInsert(&hp, 2);//��������
//	HPInsert(&hp, 3);//��������
//	Print(hp);
//	HPPop(&hp);
//	Print(hp);
//	return 0;
//}

//
//void AdjustDwon(int* a, int n, int root)
//{
//	int child = root * 2 + 1;//�������ӱȽϴ�
//	while (child < n)
//	{
//		if ((child + 1 < n) && a[child] < a[child + 1])
//			child++;
//
//		if (a[root] < a[child])//�����򽨴��
//		{
//			Swap(&a[root], &a[child]);
//			root = child;
//			child = root * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void HeapSort(int* a, int n)
//{
//	//���Ƚ��� -- 1)�����򽨴��, 2)�Ž���С��
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDwon(a, n, i);
//	}
//
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDwon(a, end, 0);
//		end--;
//	}
//}
//
////������
//int main()
//{
//	int nums[] = {5, 2, 3, 1};
//	int size = sizeof(nums) / sizeof(nums[0]);
//	HeapSort(nums, size);
//	for (int i = 0; i < size; i++)
//		printf("%d ", nums[i]);
//	return 0;
//}
