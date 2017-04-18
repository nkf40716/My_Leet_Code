int findMaxConsecutiveOnes(int* nums, int numsSize) {
	if (!nums || numsSize <= 0)
		return 0;

	int i, cnt = 0, max = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == 1)
			cnt ++;
		else 	
			cnt = 0;
		max = max > cnt ? max : cnt;
	}
    return max;
}