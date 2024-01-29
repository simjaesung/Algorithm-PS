#include<iostream>
using namespace std;

string s[] = { "\"����Լ��� ������?\"", "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.",
			"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.",
			"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"",
			"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"","��� �亯�Ͽ���." };

void joongang(int val, int depth) {
	if (val == depth) {
		for (int j = 0; j < val; j++) cout << "____";
		cout << s[0] << '\n';
		for (int j = 0; j < val; j++) cout << "____";
		cout << s[4] << '\n';
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < val; j++) cout << "____";
			cout << s[i] << '\n';
		}
	}
	
	if (val < depth) joongang(val + 1, depth);

	for (int j = 0; j < val; j++) cout << "____";
	cout << s[5] << '\n';

}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	joongang(0, n);
	return 0;
}