//�����������飬��дһ���������������ǵĽ�����
//ʾ�� 1:
//���� : nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//��� : [2, 2]
//	 ʾ�� 2 :
// ���� : nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//  ��� : [4, 9]
//	   ˵����
//	   ��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
//	   ���ǿ��Բ�������������˳��
//   ���� :
//	 ��������������Ѿ��ź����أ��㽫����Ż�����㷨��
//		 ��� nums1 �Ĵ�С�� nums2 С�ܶ࣬���ַ������ţ�
//		 ��� nums2 ��Ԫ�ش洢�ڴ����ϣ������ڴ������޵ģ������㲻��һ�μ���
//���е�Ԫ�ص��ڴ��У������ô�죿

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