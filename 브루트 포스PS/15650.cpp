#include<iostream>
using namespace std;

bool check[10]; int ans[10];

void go(int index,int start, int n, int m)
{
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] <<' ';
		cout << '\n';
		return;
	}
	
	for (int i = start; i <= n; i++) {
		if (check[i]) continue;
		check[i] = true; ans[index] = i;
		go(index + 1, i + 1, n, m);
		check[i] = false;
	}
}



int main()
{
	int N, M; cin >> N >> M;

	go(0, 1, N, M);

	return 0;
}