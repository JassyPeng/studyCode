#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

//typedef int HPDataType;


////堆结构的定义
//typedef struct Heap
//{
//	HPDataType* _hp;//数组--存储数据
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
////堆结构的初始化
//void HPInit(Heap* hp)
//{
//	if (hp == NULL)
//	{
//		printf("初始化失败!\n");
//		return;
//	}
//	hp->_hp = NULL;
//	hp->_size = 0;
//	hp->_capacity = 0;
//}
//
//void AdjustUp(HPDataType* hp, int child)
//{
//	//////向上调整
//	int parents = (child - 1) / 2;
//	while (child > 0)
//	{
//		//建大堆,排升序
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
//	int child = parents / 2 + 1;///假设左孩子比较小
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
////堆插入元素 -- 插入成功返回true,否则返回false
//bool HPInsert(Heap* hp, HPDataType val)
//{
//	if (hp == NULL)
//		return false;
//	//此处完成扩容
//	if (hp->_capacity == hp->_size)
//	{
//		int newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
//		HPDataType* tmp = (HPDataType*)realloc(hp->_hp, newCapacity * sizeof(HPDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc");
//		}
//		//扩容成功
//		hp->_hp = tmp;
//		hp->_capacity = newCapacity;
//	}
//
//	//插入新元素
//	hp->_hp[hp->_size++] = val;
//
//	if (hp->_size == 1)
//		return true;
//
//	//将插入的元素向上调整
//	int child = hp->_size - 1;
//	AdjustUp(hp->_hp, child);
//	return true;
//}
//
//void HPPop(Heap* hp)
//{
//	assert(hp);
//	assert(hp->_size > 0);
//	//**删除堆顶元素
//	//交换首尾元素
//	Swap(&hp->_hp[0], &hp->_hp[hp->_size - 1]);
//	hp->_size--;
//	AdjustDown(hp->_hp, hp->_size, 0);
//}
//
//int main()
//{
//	Heap hp;//创建堆
//	HPInit(&hp);//初始化堆
//	HPInsert(&hp, 1);//插入数据
//	HPInsert(&hp, 2);//插入数据
//	HPInsert(&hp, 3);//插入数据
//	Print(hp);
//	HPPop(&hp);
//	Print(hp);
//	return 0;
//}

//
//void AdjustDwon(int* a, int n, int root)
//{
//	int child = root * 2 + 1;//假设左孩子比较大
//	while (child < n)
//	{
//		if ((child + 1 < n) && a[child] < a[child + 1])
//			child++;
//
//		if (a[root] < a[child])//排升序建大堆
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
//	//首先建堆 -- 1)排升序建大堆, 2)排降序建小堆
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
////堆排序
//int main()
//{
//	int nums[] = {5, 2, 3, 1};
//	int size = sizeof(nums) / sizeof(nums[0]);
//	HeapSort(nums, size);
//	for (int i = 0; i < size; i++)
//		printf("%d ", nums[i]);
//	return 0;
//}
