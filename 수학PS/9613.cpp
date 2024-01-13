#include<iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() 
{
	int n, t , ans;
	cin >> n;
	int list[100];
	while (n--) {
		ans = 0;
		cin >> t;
		
		for (int i = 0; i < t; i++) {
			cin >> list[i];
		}

		for (int i = 0; i < t; i++) {
			for (int j = i + 1; j < t; j++) {
				ans += gcd(list[i], list[j]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}