#include <iostream>
#include <string>
using namespace std;

int main()
{
	string buff;
	int i(100);

	while (i-- > 0) {
		getline(cin, buff);
		cout << buff << endl;
	}
	return 0;
}