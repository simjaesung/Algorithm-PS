#include<iostream>
#include<algorithm>
using namespace std;

int a[10], num[10];
bool c[10];

void go(int index, int n, int m) 
{
	if (index == m) {
		for (int i = 0; i < m; i++) 
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i]) continue;
		c[i] = true; a[index] = num[i]; 
		go(index + 1, n, m);
		c[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);

	go(0, n, m);

	return 0;
}