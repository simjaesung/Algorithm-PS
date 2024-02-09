#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000005];

void QuickSort(int s, int e)
{
	if (s > e) return;
	int p = arr[s];
	int l = s + 1;
	int r = e - 1;

	while (1) {
		while (l <= r && arr[l] <= p)l++;
		while (l <= r && arr[r] >= p)r--;
		if (r < l) break;
		swap(arr[l], arr[r]);
	}
	swap(arr[s], arr[r]);
	QuickSort(s, r);
	QuickSort(r + 1, e);
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	QuickSort(0, n);

	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
	return 0;
}