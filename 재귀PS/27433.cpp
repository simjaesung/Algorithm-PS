#include<iostream>
using namespace std;


long long factorial(int n) {
	if (n == 0) return 1;

	return n* factorial(n - 1);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	cout << factorial(n);

	return 0;
}