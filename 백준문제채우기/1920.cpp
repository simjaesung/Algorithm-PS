#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll arr1[100005];
ll arr2[100005];
int n, m;

int bs(int s) {
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr1[mid] == s) return 1;
		else if (s < arr1[mid]) end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr1[i];
	sort(arr1, arr1 + n);

	cin >> m;
	for (int i = 0; i < m; i++) cin >> arr2[i];

	for (int i = 0; i < m; i++) cout << bs(arr2[i]) << '\n';
	return 0;
}
