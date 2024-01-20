#include<iostream>
#include<algorithm>
using namespace std;

int a[10005];

bool next_permutation(int* a, int n)
{
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i--;
	if (i <= 0) return false;

	int j = n - 1;
	while (a[j] <= a[i - 1]) j--;
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++; j--;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (next_permutation(a, n)) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	}
	else cout << -1;

	return 0;
}