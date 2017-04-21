int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void merge(int* nums1, int m, int* nums2, int n) {
	memcpy(nums1 + m, nums2, sizeof(int) * n);
	qsort(nums1, (m + n), sizeof(int), compare);
}