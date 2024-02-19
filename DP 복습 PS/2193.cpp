#include<iostream>
using namespace std;

long long d[100];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	d[1] = 1; d[2] = 1;
	for (int i = 3; i <= 90; i++) d[i] = d[i - 2] + d[i - 1];

	int n; cin >> n;
	cout << d[n];
	
	return 0;
}