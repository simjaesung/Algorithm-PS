#include<iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	if (m <= n) {
		if (m < 3) cout << "NEWBIE!";
		else cout << "OLDBIE!";
	}
	else cout << "TLE!";
	
	return 0;
}