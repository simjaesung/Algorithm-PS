#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int arr[100005];
int n, m, idx, ans = INT_MAX;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		idx = lower_bound(arr + i, arr + n, arr[i] + m) - arr;
		if(idx < n)	ans = min(ans, arr[idx] - arr[i]);
	}
	cout << ans;
	return 0;
}