bool isPowerOfFour(int n) {
	int num = 1;
	if (n <= 0) return false;
	while (num > 0 && num < INT_MAX)
	{
		if (n == num) return true;	
		num *= 4;
	}
	return false;
}