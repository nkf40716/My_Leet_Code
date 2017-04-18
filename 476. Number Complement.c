// 這題解法很多，這裡只提供我的想法，網路上很多神人可以一行解掉
// 找出最大bit位置後可得到mask 再用mask跟number做XOR運算即可得補數
int findComplement(int num) {
	if (num == 0) return 1;

	int i = 30;					// (1 << 31) 這個是signed bit, 所以從30開始
	int n = num & 0x7fffffff;	// 去掉signed bit
	
	while (i >= 0)				// 找出Most Bit位置
	{
		if (n & (1 << i)) break;
		i--;
	}

	n = (1 << (i + 1)) - 1;
	n ^= num;
	
	return n;
}