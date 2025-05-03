#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>



typedef int HPDataType;

//堆结构的定义
typedef struct Heap
{
	HPDataType* _hp;//数组--存储数据
	int _size;
	int _capacity;
}Heap;

//void Swap(HPDataType* x, HPDataType* y)
//{
//	HPDataType tmp = *x;
//	*x = *y;
//	*y = tmp;
//}

//堆结构的初始化
void HPInit(Heap* hp)
{
	if (hp == NULL)
	{
		printf("初始化失败!\n");
		return;
	}
	hp->_hp = NULL;
	hp->_size = 0;
	hp->_capacity = 0;
}

//堆插入元素 -- 插入成功返回true,否则返回false
bool HPInsert(Heap* hp, HPDataType val)
{
	if (hp == NULL)
		return false;
	//此处完成扩容
	if (hp->_capacity == hp->_size)
	{
		int newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_hp, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc");
		}
		//扩容成功
		hp->_hp = tmp;
		hp->_capacity = newCapacity;
	}
	
	//插入新元素
	hp->_hp[hp->_size++] = val;

	if (hp->_size == 1)
		return true;
	//////向上调整
	int child = hp->_size - 1;
	int parents = (child - 1) / 2;
	while (child > 0)
	{
		//建大堆
		if (hp->_hp[parents] < hp->_hp[child])
		{
			Swap(&hp->_hp[parents], &hp->_hp[child]);
			child = parents;
			parents = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
	return true;
}


int main()
{
	Heap hp;//创建堆
	HPInit(&hp);//初始化堆
	HPInsert(&hp, 1);//插入数据
	HPInsert(&hp, 2);//插入数据
	HPInsert(&hp, 3);//插入数据
	for (int i = 0; i < hp._size; i++)
		printf("%d ", hp._hp[i]);

	return 0;
}

