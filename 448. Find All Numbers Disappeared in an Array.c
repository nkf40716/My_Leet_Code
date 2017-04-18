// 49ms, beat 97.33% !!
// 只要掃一遍 有出現數字的index+1 
// 再搜剩下是0的就是消失的數字
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	int i, cnt;
	int *res = (int *)calloc(sizeof(int), numsSize);

	for (i = 0; i < numsSize; i++)
		res[nums[i] - 1]++;

	for (i = 0, cnt = 0; i < numsSize; i++)
	{
		if (res[i] == 0)
			res[cnt++] = i + 1;
	}

	*returnSize = cnt;
	return res;
}