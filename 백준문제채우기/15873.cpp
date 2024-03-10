#include<iostream>
using namespace std;
int n, ans;
int main()
{
	cin >> n;
	while (n > 0) {
		if (n % 10 == 0) {
			ans += n % 100;
			n /= 100;
		}
		else {
			ans += n % 10;
			n /= 10;
		}
	}
	cout << ans;

	return 0;
}