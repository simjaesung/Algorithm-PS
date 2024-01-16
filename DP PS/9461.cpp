#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	long long arr[101];
	arr[0] = 0;
	arr[1] = 1, arr[2] = 1, arr[3] = 1;
	arr[4] = 2;
	
	for (int i = 5; i <= 100; i++)	arr[i] = arr[i - 1] + arr[i - 5];

	int n,val;
	cin >> n;
	while (n--) {
		cin >> val;
		cout << arr[val] << '\n';
	}
	return 0;
}