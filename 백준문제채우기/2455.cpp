#include<iostream>
using namespace std;

int main()
{
	int inT = 0;
	int ans = 0;
	while (1) {
		int a, b;
		cin >> a >> b;
		inT += b;
		inT -= a;
		ans = max(ans, inT);

		if (b == 0) break;
	}
	cout << ans;
	
	return 0;
}