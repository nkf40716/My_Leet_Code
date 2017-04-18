// 懶得想，直接用暴力法，慢
int singleNumber(int* nums, int numsSize) {
	int i, res = 0, max = 0;
    char *tmp = NULL, *p = NULL;

	for (i = 0; i < numsSize; i++) {
		if (abs(nums[i]) > max) 
			max = abs(nums[i]);
	}

	tmp = (char *)calloc(sizeof(char), (max << 1) + 1);
	p = tmp + max;
	for (i = 0; i < numsSize; i++)	
		p[nums[i]]++;

	for (i = 0; i < (max << 1) + 1; i++) {
		if (tmp[i] == 1) {
			res = i - max;
			break;
		}
	}
	
	free(tmp);
	return res;
}


// 參考網路上大神解法，利用XOR交換律，超快超簡潔，有夠神。從下面C++改過來的
int singleNumber(int* nums, int numsSize) {

	int i = 1, r = nums[0];
	while (i < numsSize)
		r ^= nums[i++];

	return r;
}

// 這是網路高手的C++ Code
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            result ^= nums[i];
        }
 
        return result;
    }
    */
};
