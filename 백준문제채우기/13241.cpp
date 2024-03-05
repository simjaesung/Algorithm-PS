#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	while (b != 0) {
		ll r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b; cin >> a >> b;
	cout << a * b / gcd(a, b);
	return 0;
}