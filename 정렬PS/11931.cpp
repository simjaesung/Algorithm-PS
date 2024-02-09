#include<iostream>
using namespace std;

int arr[1000005];
int tmp[1000005];

void merge(int s, int e)
{
	int m = (s + e) / 2;
	int k1 = s; int k2 = m;

	for (int i = s; i < e; i++) {
		if (k1 == m) tmp[i] = arr[k2++];
		else if (k2 == e) tmp[i] = arr[k1++];
		else if (arr[k1] < arr[k2]) tmp[i] = arr[k2++];
		else tmp[i] = arr[k1++];
	}

	for (int i = s; i < e; i++) arr[i] = tmp[i];
}


void mergesort(int s, int e)
{
	if (s + 1 == e) return;
	int m = (s + e) / 2;

	mergesort(s, m);
	mergesort(m, e);
	merge(s, e);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	mergesort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
	
	return 0;
}