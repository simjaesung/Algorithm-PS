#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int arr[300005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	if (n == 0) {
		cout << 0; return 0;
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);

	int k = round(double(n) * 0.15);	
	for (int i = 0; i < k; i++) sum -= arr[i];
	for (int i = n-1; i > n-1-k; i--) sum -= arr[i];

	cout << round(sum / (n - (2 * k)));
	return 0;
}