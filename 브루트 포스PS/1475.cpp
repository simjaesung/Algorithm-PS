#include <iostream>
using namespace std;

int main()
{
	int cnt[10] = { 0 };
	int n,ans = 1;
	cin >> n;
	
	while (n > 0) {
		cnt[n % 10]++;
		n /= 10;
	}
	cnt[9] += cnt[6];
	cnt[6] = 0;
	cnt[9] = cnt[9] % 2 + cnt[9] / 2;

	for (auto x : cnt) ans = max(ans, x);

	cout << ans;

	return 0;
}