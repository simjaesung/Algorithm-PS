#include<iostream>
using namespace std;

int arr[10001];

bool prev_permutation(int* a, int n) 
{
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) i--;
	if (i <= 0) return false;

	int j = n - 1;
	while (a[i - 1] <= a[j]) j--;
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) swap(a[i++], a[j--]);
	return true;
}


int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	if (prev_permutation(arr, n))
		for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	else cout << -1;

	return 0;
}