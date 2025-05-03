#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>



typedef int HPDataType;

//�ѽṹ�Ķ���
typedef struct Heap
{
	HPDataType* _hp;//����--�洢����
	int _size;
	int _capacity;
}Heap;

//void Swap(HPDataType* x, HPDataType* y)
//{
//	HPDataType tmp = *x;
//	*x = *y;
//	*y = tmp;
//}

//�ѽṹ�ĳ�ʼ��
void HPInit(Heap* hp)
{
	if (hp == NULL)
	{
		printf("��ʼ��ʧ��!\n");
		return;
	}
	hp->_hp = NULL;
	hp->_size = 0;
	hp->_capacity = 0;
}

//�Ѳ���Ԫ�� -- ����ɹ�����true,���򷵻�false
bool HPInsert(Heap* hp, HPDataType val)
{
	if (hp == NULL)
		return false;
	//�˴��������
	if (hp->_capacity == hp->_size)
	{
		int newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_hp, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc");
		}
		//���ݳɹ�
		hp->_hp = tmp;
		hp->_capacity = newCapacity;
	}
	
	//������Ԫ��
	hp->_hp[hp->_size++] = val;

	if (hp->_size == 1)
		return true;
	//////���ϵ���
	int child = hp->_size - 1;
	int parents = (child - 1) / 2;
	while (child > 0)
	{
		//�����
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
	Heap hp;//������
	HPInit(&hp);//��ʼ����
	HPInsert(&hp, 1);//��������
	HPInsert(&hp, 2);//��������
	HPInsert(&hp, 3);//��������
	for (int i = 0; i < hp._size; i++)
		printf("%d ", hp._hp[i]);

	return 0;
}

