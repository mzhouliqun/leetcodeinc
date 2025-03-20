#include <stdio.h>
#include <stdlib.h>
int* twoSum(int *, int, int);
void displayArray(int *, int);
int main(void)
{
	int nums[] = {2, 7, 11, 15};
//	int nums[] = {3, 2, 4};
//	int nums[] = {3, 3};
	int target = 9;
//	int target = 6;
//	int target = 6;

	int *result;
	int len = (int)(sizeof(nums) / sizeof(int));

	result = twoSum(nums, len, target);
	displayArray(result, 2);
	free(result);

	return 0;
}

void displayArray(int *arr, int length)
{
	printf("[");
	for (int i = 0; i < length; i++) {
		printf("%d", *(arr + i));
		if ((length - i -1) > 0)
			printf(",");
	}
	printf("]\n");
}

int* twoSum(int* nums, int numsSize, int target)
{
	int i, j;
	int flag = 0;
	int result[2];
	int *out;

	for (i = 0; i < numsSize; i++) {
		for (j = 0; j < numsSize; j++) {
			if (i != j) {
				if (target == (nums[i] + nums[j]))
					{
					result[0] = i;
					result[1] = j;
					flag = 1;
					break;
				}
			}
		}
		if (flag)
			break;
	}
	out = (int *)malloc(sizeof(int) * 2);
	out[0] = result[0] < result[1] ? result[0] : result[1];
	out[1] = result[0] > result[1] ? result[0] : result[1];
	return out;
}
