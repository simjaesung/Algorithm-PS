#include<iostream>
using namespace std;

int a[10];

void go(int index, int select, int n, int m)
{
	if (select == m) {
		for (int i = 0; i < m; i++)cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	if (index > n) return;

	a[select] = index;
	go(index + 1, select + 1, n, m);
	a[select] = 0;
	go(index + 1, select, n, m);
}

int main()
{
	int n, m; cin >> n >> m;
	go(1, 0, n, m);
	return 0;
}