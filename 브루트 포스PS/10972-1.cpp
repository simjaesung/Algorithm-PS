#include<iostream>
using namespace std;

int arr[10001];

bool next_purmutaion(int* a, int n)
{
	int i = n;
	while (i > 1 && arr[i - 1] >= arr[i]) i--;
	if (i <= 1) return false;
	int j = n;
	while (arr[i - 1] >= arr[j]) j--;
	swap(arr[i - 1], arr[j]);
	j = n;
	while (i < j) swap(arr[i++], arr[j--]);
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	if (next_purmutaion(arr, n)) {
		for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
	}
	else cout << -1;
	
	return 0;
}