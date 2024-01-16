#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, ans = 0;
	cin >> n;

	int arr[1001], LIS[1001];

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		LIS[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				LIS[i] = max(LIS[i], LIS[j] + 1);
			}
		}
		ans = max(ans, LIS[i]);
	}

	cout << ans <<'\n';

	int k = 1000,idx = n;
	stack<int>s;
	for (int i = ans; i >= 1; i--) {
		for (int j = idx; j >= 1; j--) {
			if (LIS[j] == i && k > arr[j]) {
				k = arr[j];
				idx = j;
			}
		}
		s.push(k);
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}