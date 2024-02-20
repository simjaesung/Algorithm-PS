#include<iostream>
#include<limits.h>
using namespace std;

int arr[100005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int val = 1;
	for (int i = 1; i <= 100000; i++) {
		if (i == val * val) {
			arr[i] = 1;	val++;
		}
		else {
			int k = INT_MAX;
			for (int j = 1; j < val; j++) {
				k = min(k, arr[j * j] + arr[i - j * j]);
			}
			arr[i] = k;
		}
	}

	int n; cin >> n;
	cout << arr[n];

	return 0;
}