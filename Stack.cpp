#include "DS.h"

using namespace std;


/* *************************************************/
void stack(void) {
	//class ����
	Stack S;

	//var ����
	int select = 0;

	while(1)
	{
		cout << "push:1  pop:2  show:3  ����:4\n";
		//��� �Է�
		cin >> select;

		switch (select) {

		case 1:
			S.push();
			continue;

		case 2:
			S.pop();
			continue;

		case 3:
			S.show();
			continue;

		case 4:
			cout << "�����մϴ�.\n";
			break;

		default:
			cout << "1,2,3,4 �߿��� ����\n";
		}
		break;
	}
}

/*push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.*/