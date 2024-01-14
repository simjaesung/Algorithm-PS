#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int>memo(n + 1);

	for (int i = 2; i <= n; i++) {
		memo[i] = memo[i - 1] + 1;
		if (i % 3 == 0) memo[i] = min(memo[i], memo[i / 3] + 1);
		if (i % 2 == 0) memo[i] = min(memo[i], memo[i / 2] + 1);
	}

	cout << memo[n];

	return 0;
}