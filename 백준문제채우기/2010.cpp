#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int plug = 1 - n;

	while (n--) {
		int val; cin >> val;
		plug += val;
	}
	cout << plug;
	
	return 0;
}