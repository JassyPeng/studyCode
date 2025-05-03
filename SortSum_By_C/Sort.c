#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


////插入排序
//void InsertSort(int arr[], int size)
//{
//	//默认认为i之前的元素都已排列整齐
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

////希尔排序的实现
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


////选择排序
//void SelectSort(int* arr, int sz)
//{
//	int begin = 0, end = sz - 1;
//	while (begin < end)
//	{
//		int mini = begin, maxi = begin;
//		for (int i = begin + 1; i <= end; i++)
//		{
//			//在这里更新mini以及maxi的值
//			if (arr[i] < arr[mini])
//				mini = i;
//			if (arr[i] > arr[maxi])
//				maxi = i;
//		}
//		//跳出循环后尝试交换将两者值移到首和尾
//		Swap(&arr[begin], &arr[mini]);
//			if (begin == maxi)//预防最大值出现在begin位置导致交换后最大值丢失
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
////快速排序
////版本一: Hoare
////优化点1:首中尾三数取中
////优化点2:小区间插入排序
//int GetMidi(int* arr, int left, int right)
//{
//	int midi = (left + right) / 2;
//	//找到三数的中间值
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
//	//优化1:
//	//该函数仅完成一趟的快排
//	
//	//优化前
//	// int keyi = left;
//	
//	//优化后
//	int mid = GetMidi(arr, left, right);
//	Swap(&arr[left], &arr[mid]);
//
//	int keyi = left;
//	int begin = left, end = right;
//	while(begin < end)
//	{
//		//右边找小
//		while (begin < end && arr[end] >= arr[keyi])
//			end--;
//		//左边找大
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
//	//优化2:
//	//小区间优化:将递归最后
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
	//test01();//插入排序 - SelectSort
	//test02();//希尔排序 - ShellSort
	//test03();//选择排序 - SelectSort
	//test04();//堆排序 - HeapSort -- 未完成
	//test05();//冒泡排序 - BubbleSort
	test06();//快速排序 - QuickSort
	return 0;
}