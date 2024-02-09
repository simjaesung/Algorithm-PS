#include<iostream>
using namespace std;

int arr1[1000001],arr2[1000001], arr3[2000005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> arr1[i];
	for (int j = 0; j < m; j++) cin >> arr2[j];

	int s1 = 0, s2 = 0;

	for (int i = 0; i < n + m; i++) {
		if (s1 == n) arr3[i] = arr2[s2++];
		else if (s2 == m) arr3[i] = arr1[s1++];
		else if (arr1[s1] <= arr2[s2]) arr3[i] = arr1[s1++];
		else arr3[i] = arr2[s2++];
	}
	
	for (int i = 0; i < n + m; i++) cout << arr3[i] << ' ';


	return 0;
}