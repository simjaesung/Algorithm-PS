#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(nullptr), cin.tie(nullptr);

	int n, val;
	cin >> n;
	vector<long long>arr(1000001);

	arr[1] = 1, arr[2] = 2, arr[3] = 4;

	for (int i = 4; i <= 1000000; i++) {
		arr[i] = (arr[i - 3] + arr[i - 2] + arr[i - 1]) % 1000000009;
	}

	while (n--) {
		cin >> val;
		cout << arr[val] << '\n';
	}
	return 0;
}