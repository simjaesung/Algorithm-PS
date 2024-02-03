#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int ans[10], check[10], arr[10];

void go(int k)
{
	if (k == m) {
		for (int i = 0; i < m; i++) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (tmp == arr[i]) continue;
		ans[k] = arr[i]; tmp = arr[i];
		go(k + 1);
	}
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	go(0);

	return 0;
}