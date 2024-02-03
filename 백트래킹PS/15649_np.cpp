#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int arr[8];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) arr[i-1] = i;

	do {
		for (int k = 0; k < m; k++)	cout << arr[k] << ' ';
		cout << '\n';

		reverse(arr + m, arr + n);

	} while (next_permutation(arr, arr + n));

	
	return 0;
}