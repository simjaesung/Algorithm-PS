#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;

	while (n > 0) {
		cout << "long" << ' ';
		n -= 4;
	}
	cout << "int";
	
	return 0;
}