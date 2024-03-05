#include<iostream>
#include<algorithm>
using namespace std;
int arr[100005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int m; cin >> m;
	while (m--) {
		int val; cin >> val;
		int k = lower_bound(arr, arr + n, val) - arr;
		if (val == arr[k]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	
	return 0;
}