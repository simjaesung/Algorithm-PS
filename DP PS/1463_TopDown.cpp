#include<iostream>
#include<vector>

using namespace std;

int arr[1000001];

int go(int n) {
	if (n == 1) return 0;
	if (arr[n] > 0) return arr[n];
	arr[n] = go(n - 1) + 1;

	if (n % 2 == 0) {
		int temp = go(n / 2) + 1;
		arr[n] = min(arr[n], temp);
	}

	if (n % 3 == 0) {
		int temp = go(n / 3) + 1;
		arr[n] = min(arr[n], temp);
	}

	return arr[n];
}

int main()
{
	int n;
	cin >> n;

	cout << go(n);

	return 0;
}