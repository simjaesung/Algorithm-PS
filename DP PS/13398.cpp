#include<iostream>

using namespace std;
int num[100001];
int D1[100001];
int D2[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, ans = -1000;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> num[i];

	D1[1] = num[1], D2[n] = num[n];

	for (int i = 2; i <= n; i++) D1[i] = max(D1[i - 1] + num[i], num[i]);
	for (int j = n - 1; j >= 1; j--) D2[j] = max(D2[j + 1] + num[j], num[j]);

	for (int i = 1; i <= n; i++) ans = max(ans, D1[i]);
	for (int i = 2; i <= n-1; i++)ans = max(ans, D1[i-1]+D2[i+1]);

	cout << ans ;

	return 0;
}