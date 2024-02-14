#include<iostream>
using namespace std;

int arr[55][2];
int c[55];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1]) c[i]++;
		}
	}

	for (int i = 0; i < n; i++) cout << c[i] + 1 << ' ';


	return 0;
}