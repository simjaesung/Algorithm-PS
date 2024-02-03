#include<iostream>
using namespace std;
int n, m;

int check[10], ans[10];

void go(int k, int start) 
{
	if (k == m) {
		for (int i = 0; i < m; i++) cout << ans[i] << ' ';
		cout << '\n';
	}

	for (int i = start; i <= n; i++) {
		if (check[i]) continue;
		check[i] = 1; ans[k] = i;
		go(k + 1, i + 1);
		check[i] = 0;
	}

}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	go(0, 1);
	return 0;
}