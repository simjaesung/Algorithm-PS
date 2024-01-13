#include<iostream>

using namespace std;

int sosoo(int n)
{
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}

	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		if (sosoo(i)) {
			while (n % i == 0) {
				n /= i;
				cout << i <<'\n';
			}
		}
	}
	
	return 0;
}