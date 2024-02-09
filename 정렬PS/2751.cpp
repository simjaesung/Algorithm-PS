#include<iostream>
using namespace std;

int arr[1000005];
int tmp[1000005];


void merge(int st, int en)
{
	int m = (st + en) / 2;
	int k1 = st; int k2 = m;
	for (int i = st; i < en; i++) {
		if (k1 == m) tmp[i] = arr[k2++];
		else if (k2 == en) tmp[i] = arr[k1++];
		else if (arr[k2] >= arr[k1]) tmp[i] = arr[k1++];
		else tmp[i] = arr[k2++];
	}

	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void mergesort(int st, int en)
{
	if (st + 1 == en) return;
	int m = (st + en) / 2;
	mergesort(st, m);
	mergesort(m, en);

	merge(st, en);
}



int main()
{
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	mergesort(0, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}