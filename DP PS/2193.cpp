#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	long long pnn[91] = { 0 };
	pnn[0] = 0, pnn[1] = 1;

	for (int i = 2; i <= N; i++) {
		pnn[i] = pnn[i - 1] + pnn[i - 2];
	}
	cout << pnn[N];

	return 0;
}