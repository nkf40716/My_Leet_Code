// 很慢，懶得找別的解法了，比較好的方法應是用Stack去解
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
	if (!nums || numsSize <= 0){
		*returnSize = 0;
		return NULL;
	}
	int i, j, idx;
	int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

	for (i = 0; i < numsSize; i++)
	{
		j = numsSize;
		idx = (i + 1) % numsSize;
		while (j)
		{
			if (nums[idx] > nums[i])
				break;
			idx = (idx + 1) % numsSize;
			j--;
		}
		res[i] = ((j == 0) ? (-1) : (nums[idx]));
	}
	return res;
}
