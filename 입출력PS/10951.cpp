#include <iostream>
using namespace std;

int main()
{
	int A, B;

	while (1) {
		cin >> A >> B;
		if (cin.eof() == 1)
			break;

		cout << A + B << endl;
	}

	return 0;
}