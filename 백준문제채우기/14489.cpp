#include<iostream>
using namespace std;
int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	if ((c + c) <= (a + b)) {
		cout << a + b - (2 * c);
	}
	else cout << a + b;
	
	return 0;
}