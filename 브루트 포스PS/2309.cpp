#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int nan[9];
	int sum = 0, check = 0,a, b;

	for (int i = 0; i < 9; i++) {
		cin >> nan[i];
		sum += nan[i];
	}

	for (int i = 0; i < 9; i++) {
		if (check) break;

		a = nan[i];
		for (int j = i+1; j < 9; j++) {
			if (a + nan[j] == sum - 100) {
				b = nan[j];
				check = 1;
				break;
			}	
		}
	}
	
	sort(nan, nan + 9);

	for (auto x : nan) {
		if (x != a && x != b) cout << x << '\n';
	}
	
	return 0;
}