#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[10];

int main()
{
	int n, m, k;
	cin >> n >> m;
	k = n - m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	vector<int>s;
	while (m--) s.push_back(0);
	while (k--) s.push_back(1);

	do {
		for (int i = 0; i < n; i++)
			if (s[i] == 0) cout << arr[i] << ' ';
		cout << '\n';

	} while (next_permutation(s.begin(), s.end()));

	return 0;
}
