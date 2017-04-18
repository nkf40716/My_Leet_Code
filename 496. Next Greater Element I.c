// 自己寫的，直接暴力法用迴圈找，12ms
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
	if (!findNums || !findNumsSize || !nums || !numsSize) {
		*returnSize = 0;
		return NULL;
	}

	int *res = (int *)malloc(sizeof(int) * findNumsSize);
	int i, j, n;

	for (i = 0; i < findNumsSize; i++)
	{
		for (j = 0, n = -1; j < numsSize; j++)
		{
			if (findNums[i] == nums[j]) {
				j++;
				break;
			}
		}
		for (; j < numsSize; j++)
		{
			if (nums[j] > findNums[i]) {
				n = j;
				break;
			}
		}
		res[i] = ((n == -1) ? (n) : (nums[n]));
	}

	*returnSize = findNumsSize;
    return res;
}

// 第二種，參考別人解法用HashTable，速度快很多 3~6ms
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    int* returnArray = NULL;
    int* numsHash = NULL;
	int i, j;

    *returnSize = findNumsSize;

    if(findNums != NULL && findNumsSize != 0 && nums != NULL && numsSize != 0) 
	{
        /* find the max element in the nums */
        int max = 0;
        for(i = 0; i < numsSize; i++) {
            if(max < nums[i])
                max = nums[i];
        }

		returnArray = (int *)malloc((*returnSize) * sizeof(int));
		numsHash = (int *)malloc((max+1) * sizeof(int));
		
        /* hash the nums' element to numsHash, the key is nums's element, */
        /* the velue is the next greater element, or -1 if does not exist */
        /* nums[numsSize-1] is the last element of nums, don't have next, */
        /* so set it to -1 directly */
        for(i = 0; i < numsSize-1; i++) {
            numsHash[nums[i]] = -1;
            for(j = i+1; j < numsSize; j++) {
                if(nums[j] > nums[i]) {
                    numsHash[nums[i]] = nums[j];
                    break;
                }
            }
        }
        numsHash[nums[numsSize-1]] = -1;

        /* find the next greater element */
        for(i = 0; i < findNumsSize; i++) {
            returnArray[i] = numsHash[findNums[i]];
        }
    }

    return returnArray;
}