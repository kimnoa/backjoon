#include "DS.h"

using namespace std;

int main(void) {

	//�ӵ� ���
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int select = 0;

	cout << "����� �ڷ� ������ �������ּ���.\n";
	cout << "1: ����  2: ���� ����Ʈ  3: Ʈ�� \n";
	while (1) {
		cin >> select;
		if (select != 1 && select != 2 && select != 3)
		{
			cout << " 1, 2, 3 �߿��� �������ּ���\n";
			continue;
		}
		break;
	}
	switch (select)
	{
	case 1:
		stack();
		break;

	case 2:
		linkedlist();
		break;

	case 3:
		binary_tree();
	}


	return 0;
}

