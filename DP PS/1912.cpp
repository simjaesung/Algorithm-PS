#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, ans;
	cin >> n;

	vector<int>arr(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	ans = arr[1];

	for (int i = 2; i <= n; i++) {
		arr[i] = max(arr[i], arr[i - 1] + arr[i]);
		ans = max(arr[i], ans);
	}
	
	cout << ans;
	
	return 0;
}