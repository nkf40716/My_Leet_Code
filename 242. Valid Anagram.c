bool isAnagram(char* s, char* t) {
	int i, n = strlen(s);

	if (n != strlen(t))
		return false;

	int cnt[26] = {0};
	for (i = 0; i < n; ++i)
	{
		++cnt[s[i] - 'a'];
		--cnt[t[i] - 'a'];
	}
	for (i = 0; i < 26; ++i)
		if (cnt[i]) return false;

	return true;
}
