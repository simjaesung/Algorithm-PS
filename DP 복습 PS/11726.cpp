#include<iostream>
using namespace std;

int d[1005];

int main()
{
	int n; cin >> n;
	d[1] = 1; d[2] = 2;
	for (int i = 3; i <= 1000; i++)
		d[i] = d[i - 2] + d[i - 1];

	cout << d[n];
	
	
	return 0;
}