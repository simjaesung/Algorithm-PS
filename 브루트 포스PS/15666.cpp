#include<iostream>
#include<algorithm>
using namespace std;

int n, m, num[10], a[10];

void go(int index, int start)
{
	if (index == m) {
		for (int i = 0; i < m; i++) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = start; i < n; i++) {
		if (tmp == num[i]) continue;
		tmp = num[i];  a[index] = num[i];
		go(index + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	go(0, 0);
	return 0;
}