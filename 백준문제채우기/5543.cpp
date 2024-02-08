#include<iostream>
using namespace std;

int main()
{
	int b1, b2, b3, v1, v2;
	cin >> b1 >> b2 >> b3 >> v1 >> v2;

	int b = min(b3, min(b1, b2));
	int v = min(v1, v2);

	cout << b + v - 50;
	
	return 0;
}