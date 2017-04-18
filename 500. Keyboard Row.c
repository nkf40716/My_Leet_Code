// GenKeyBoardTable: 產生紀錄char是屬於哪一列的Table.
void GenKeyBoardTable(char *table, int tableSize)
{
	if (!table) return;
	char *keyboard[2] = {"asdfghjkl", "zxcvbnm"};
	char *keyboard2[2] = {"ASDFGHJKL", "ZXCVBNM"};
	memset(table, 0, tableSize);	// 假設第一個Row都是0，所以上面省去第一個Row的char

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < (int)strlen(keyboard[i]); j++) 
		{
			table[keyboard[i][j]] = table[keyboard2[i][j]] = i + 1;
		}
	}
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize)
 {
	if (!words) return NULL;

	bool match = true;
	int retSize = 0, i, j, n;
	int *rec = (int *)calloc(sizeof(int), wordsSize);
	char *table = (char *)malloc(sizeof(char) * 256);
	char **ret = NULL;

	GenKeyBoardTable(table, 256);

	for (i = 0; i < wordsSize; i++)
	{
		match = true;
		n = strlen(words[i]);
		for (j = 0; j < n - 1; j++)
		{
			if (table[words[i][j]] != table[words[i][j+1]])
			{
				match = false;
				break;
			}
		}
		if (match == true) {
			rec[retSize] = i;
			retSize++;
		}
	}

	ret = (char **)malloc(sizeof(char*) * retSize);
	for (i = 0; i < retSize; i++)
	{
		n = strlen(words[rec[i]]);
		ret[i] = (char *)malloc(sizeof(char) * (n + 1));
		memcpy(ret[i], words[rec[i]], sizeof(char) * (n + 1));
	}

	free(rec);
	free(table);
	*returnSize = retSize;
    return ret;
}