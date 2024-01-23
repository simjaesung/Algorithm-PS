#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int>s(n);

	for (int i = 0; i < n; i++) cin >> s[i];

	if (prev_permutation(s.begin(), s.end()))
		for (int i = 0; i < n; i++) cout << s[i] << ' ';
	else cout << -1;
	
	return 0;
}