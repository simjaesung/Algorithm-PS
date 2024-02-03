#include<iostream>
using namespace std;

int n, s,ans = 0;
int arr[25], check[25];

void go(int select, int index, int m, int sum)
{
	//m개를 골랐을 때 sum이 합과 동일하면 조건 만족
	if (select == m) {
		if (sum == s) ans++;
		return;
	}
	
	if (index > n - 1) return;
	//하나 고르고 sum에 그 값을 추가
	go(select + 1, index + 1, m, sum + arr[index]);
	//고르지 않고 다음 인덱스를 탐색
	go(select, index + 1, m, sum);
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	//k개를 고를 때 합이 s가 되는 경우의 수를 추가
	for (int k = 1; k <= n; k++) go(0, 0, k, 0);
	cout << ans;
	return 0;
}