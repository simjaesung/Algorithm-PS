#include<iostream>
#include<string>

using namespace std;

int main()
{
	//a = 97

	int result[26] = { 0 };
	string s;
	cin >> s;
	
	for (auto x : s)
		result[int(x) - 97]++;
		
	for (auto x : result)
		cout << x << ' ';

	return 0;
}
