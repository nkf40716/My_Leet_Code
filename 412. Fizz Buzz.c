char** fizzBuzz(int n, int* returnSize) {
	if (n <= 0) {
		*returnSize = 0;
		return NULL;
	}

	int size, num;
	char **res = (char **)malloc(sizeof(char*) * n);

	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 15 == 0) {
			res[i] = (char *)malloc(sizeof(char) * 9);
			res[i] = "FizzBuzz";
		}
		else if ((i + 1) % 3 == 0) {
			res[i] = (char *)malloc(sizeof(char) * 5);
			res[i] = "Fizz";
		}
		else if ((i + 1) % 5 == 0) {
			res[i] = (char *)malloc(sizeof(char) * 5);
			res[i] = "Buzz";
		}
		else
		{
			size = 0;
			num = i + 1;
			while (num % 10)
			{
				size++;	
				num /= 10;
			}
			res[i] = (char *)malloc(sizeof(char) * (size + 1));
			sprintf(res[i], "%d", (i+1));
		}
	}

	*returnSize = n;
    return res;
}