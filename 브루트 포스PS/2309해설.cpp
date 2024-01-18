#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int sum = 0;
	int nan[9];

	for (int i = 0; i < 9; i++) {
		cin >> nan[i];
		sum += nan[i];
	}

	sort(nan, nan + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (nan[i] + nan[j] == sum - 100) {
				for (int k = 0; k < 9; k++) {
					if (nan[k] != nan[i] && nan[k] != nan[j]) 
						cout << nan[k] << '\n';
				}
				return 0;
			}
		}
	}
}