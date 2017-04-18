int strStr(char* haystack, char* needle) {
	int i = 0, j = 0, idx = 0;
	int h = strlen(haystack);
	int n = strlen(needle);

	if (n > h) return -1;
	if (!n) return 0;

	while (h >= n)
	{
		if (haystack[idx] == needle[0])
		{
			for (i=1, j=1; i<n; i++)
			{
				if (!haystack[0]) break;
				if (haystack[idx+i] == needle[i]) j++;
			}
			if (j == n) return idx;
		}
		idx++;
		h--;
	}
    return -1;
}