void merge(int arr[], int l, int m, int r) {
	int s1 = m - l + 1;
	int s2 = r - m;
	int* L = new int[s1], *R = new int[s2];
	for (int i = 0; i < s1; i++)
	{
		L[i] = arr[l + i];
	}
	for (int j = 0; j < s2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	int i = 0, j = 0, k = l;
	while (i <s1 && j < s2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
		j++;}
		k++;
	}
	while (i <s1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < s2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergesort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}