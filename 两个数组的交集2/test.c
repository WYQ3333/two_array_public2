//给定两个数组，编写一个函数来计算它们的交集。
//示例 1:
//输入 : nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出 : [2, 2]
//	 示例 2 :
// 输入 : nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//  输出 : [4, 9]
//	   说明：
//	   输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
//	   我们可以不考虑输出结果的顺序。
//   进阶 :
//	 如果给定的数组已经排好序呢？你将如何优化你的算法？
//		 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
//		 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载
//所有的元素到内存中，你该怎么办？

#include<stdio.h>
#include<Windows.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int i = 0;
	int j = 0;
	long *returnNew = malloc(sizeof(long)*(nums1Size+nums2Size));
	while (j < nums1Size)
	{
		int min1 = nums1[j];
		for (i = j; i < nums1Size; i++){
			if (nums1[i] < min1){
				swap(&nums1[i], &min1);
			}
		}
		nums1[j] = min1;
		j++;
	}
	while (j < nums2Size)
	{
		int min2 = nums1[j];
		for (i = j; i < nums1Size; i++){
			if (nums1[i] < min2){
				swap(&nums1[i], &min2);
			}
		}
		nums1[j] = min2;
		j++;
	}
	if (nums1[nums1Size - 1] < nums2[0] || nums1[0]>nums2[nums2Size - 1]){
		*returnSize = 0;
		return NULL;
	}
	for (i = 0; i < nums1Size; i++)
	{
		for (j = 0; j < nums2Size; j++)
		{
			if (nums1[i] == nums2[j])
			{
				returnNew[(*returnSize)++] = nums1[i];
				i++;
			}
		}
	}
	return returnNew;
}

int main()
{
	int nums1[] = { 1,2,2,1 };
	int nums2[] = { 2,2 };
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	int input = 0;
	int * returnSize = &input;
	int *ret = intersect(nums1, nums1Size, nums2, nums2Size, returnSize);
	int i = 0;
	for (i = 0; i < *returnSize; i++)
	{
		printf("%d ", ret[i]);
	}
	system("pause");
	return 0;
}