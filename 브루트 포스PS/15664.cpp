#include<iostream>
#include<algorithm>
using namespace std;

int num[10], a[10];
int n, m;
bool c[10];

void go(int index, int start)
{
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << num[a[i]] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = start; i < n; i++) {
		if (c[i]) continue;
		if (num[i] == tmp) continue;
		tmp = num[i];
		c[i] = 1; a[index] = i;
		go(index + 1, i);
		c[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);

	go(0, 0);

	return 0;
}