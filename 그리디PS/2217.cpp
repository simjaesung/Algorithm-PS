#include<iostream>
#include<algorithm>
using namespace std;
int arr[100005];

bool compare(int a, int b) {
	return a > b;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, compare);
	int ans = arr[0];
	for (int i = 1; i < n; i++) ans = max(ans, arr[i] * (i + 1));
	cout << ans;
	return 0;
}