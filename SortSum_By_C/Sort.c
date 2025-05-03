#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


////��������
//void InsertSort(int arr[], int size)
//{
//	//Ĭ����Ϊi֮ǰ��Ԫ�ض�����������
//	for (int i = 0; i < size - 1; i++)
//	{
//		int end = i + 1;
//		int tmp = arr[end];
//		while (end > 0)
//		{
//			if (arr[end - 1] > arr[end])
//			{
//				arr[end] = arr[end - 1];
//				arr[end - 1] = tmp;
//			}
//			else
//			{
//				break;
//			}
//			end--;
//		}
//	}
//}
//
//void test01()
//{
//	int nums[] = {5, 1, 1, 2, 0, 0};
//	InsertSort(nums, sizeof(nums) / sizeof(nums[0]));
//	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

////ϣ�������ʵ��
//void ShellSort(int* arr, int size)
//{
//	int gap = size;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//
//		for (int i = 0; i < size - gap; i += gap)
//		{
//			int end = i + gap;
//			int tmp = arr[end];
//			while (end > 0)
//			{
//				if (arr[end - gap] > arr[end])
//				{
//					arr[end] = arr[end - gap];
//					arr[end - gap] = tmp;
//				}
//				else
//				{
//					break;
//				}
//				end -= gap;
//			}
//		}
//	}
//}
//
//void test02()
//{
//	int nums[] = { 2, 3, 5, 2, 1, 4};
//	//int nums[] = {5, 1, 1, 2, 0, 0};
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	ShellSort(nums, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}


////ѡ������
//void SelectSort(int* arr, int sz)
//{
//	int begin = 0, end = sz - 1;
//	while (begin < end)
//	{
//		int mini = begin, maxi = begin;
//		for (int i = begin + 1; i <= end; i++)
//		{
//			//���������mini�Լ�maxi��ֵ
//			if (arr[i] < arr[mini])
//				mini = i;
//			if (arr[i] > arr[maxi])
//				maxi = i;
//		}
//		//����ѭ�����Խ���������ֵ�Ƶ��׺�β
//		Swap(&arr[begin], &arr[mini]);
//			if (begin == maxi)//Ԥ�����ֵ������beginλ�õ��½��������ֵ��ʧ
//				maxi = mini;
//		Swap(&arr[end], &arr[maxi]);
//		begin++, end--;
//	}
//}
//
//void test03()
//{
//	//int nums[] = { 2, 3, 5, 2, 1, 4 };
//	int nums[] = { 9,1,2,5,7,4,6,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	SelectSort(nums, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//void AdjustDown()
//{
//
//}
//
//void HeapSort(int* arr, int sz)
//{
//
//}
//
//void test04()
//{
//	int nums[] = { 9,1,2,5,7,4,6,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	HeapSort(nums, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//void BubbleSort(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		int flag = 1;
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//				flag = 0, Swap(&arr[j], &arr[j + 1]);
//		}
//		if (flag)
//			break;
//	}
//}
//
//void test05()
//{
//	int nums[] = { 2, 3, 5, 2, 1, 4 };
//	//int nums[] = { 9,1,2,5,7,4,6,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	BubbleSort(nums, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}




//
////��������
////�汾һ: Hoare
////�Ż���1:����β����ȡ��
////�Ż���2:С�����������
//int GetMidi(int* arr, int left, int right)
//{
//	int midi = (left + right) / 2;
//	//�ҵ��������м�ֵ
//	if (arr[left] < arr[midi])
//	{
//		if (arr[midi] < arr[right])
//			return midi;
//		else if (arr[left] < arr[right])
//			return right;
//		else
//			return left;
//	}
//	else
//	{
//		//arr[left] > arr[midi]
//		if (arr[midi] > arr[right])
//			return midi;
//		else if (arr[left] < arr[right])
//			return left;
//		else
//			return right;
//	}
//
//}
//
//int PartSort(int* arr, int left, int right)
//{
//	//�Ż�1:
//	//�ú��������һ�˵Ŀ���
//	
//	//�Ż�ǰ
//	// int keyi = left;
//	
//	//�Ż���
//	int mid = GetMidi(arr, left, right);
//	Swap(&arr[left], &arr[mid]);
//
//	int keyi = left;
//	int begin = left, end = right;
//	while(begin < end)
//	{
//		//�ұ���С
//		while (begin < end && arr[end] >= arr[keyi])
//			end--;
//		//����Ҵ�
//		while (begin < end && arr[begin] <= arr[keyi])
//			begin++;
//		Swap(&arr[begin], &arr[end]);
//	}
//	Swap(&arr[keyi], &arr[begin]);
//	return begin;
//}
//
//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)
//		return;
//	//�Ż�2:
//	//С�����Ż�:���ݹ����
//	int keyi = PartSort(arr, left, right);
//
//	QuickSort(arr, left, keyi - 1);
//	QuickSort(arr, keyi + 1, right);
//}
//
//void test06()
//{
//	int nums[] = { 2, 3, 5, 2, 1, 4 };
//	//int nums[] = { 9,1,2,5,7,4,6,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	QuickSort(nums, 0, sz - 1);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}


int main()
{
	//test01();//�������� - SelectSort
	//test02();//ϣ������ - ShellSort
	//test03();//ѡ������ - SelectSort
	//test04();//������ - HeapSort -- δ���
	//test05();//ð������ - BubbleSort
	test06();//�������� - QuickSort
	return 0;
}