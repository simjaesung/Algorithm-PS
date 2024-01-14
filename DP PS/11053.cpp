#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	int arr[1001];
	int maxlen[1001];

	for (int i = 1; i <= n; i++) cin >> arr[i];

	maxlen[1] = 1;
	int max = arr[1];
	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		if (arr[i] > max) {
			max = arr[i];
			maxlen[i] = maxlen[i - 1] + 1;
		} 
		else {
			if (cnt > maxlen[i - 1]) {
				cnt = 0;
				max = arr[i];
				maxlen[i] = maxlen[i - 1] + 1;
			}
			else {
				cnt++;
				maxlen[i] = maxlen[i - 1];
			}
		}	
	}
	
	cout << maxlen[n];
	return 0;
}