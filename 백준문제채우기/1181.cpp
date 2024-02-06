#include<iostream>
#include<math.h>
using namespace std;
int n, m, diff, ans;
int arr[105], check[105], s[4];

void go(int select,int start)
{
	if (select == 3) {
		int sum = 0;
		//고른 3수의 합을 더함 
		for (int i = 0; i < 3; i++) sum += s[i];
		
		//합이 m을 넘어가선 안됨
		if (sum > m) return;

		int val = abs(m - sum);

		//이전의 합의 차이가 더 컸을 경우 갱신
		if (diff > val) {
			diff = val;
			ans = sum;
		}
		return;
	}

	for (int i = start; i < n; i++) {
		if (check[i]) continue;
		check[i] = 1; s[select] = arr[i];
		go(select + 1, i + 1);
		check[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	diff = m;
	go(0,0);
	cout << ans;
	return 0;
}