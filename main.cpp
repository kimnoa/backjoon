#include "DS.h"

using namespace std;

int main(void) {

	//속도 향상
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int select = 0;

	cout << "사용할 자료 구조를 선택해주세요.\n";
	cout << "1: 스택  2: 연결 리스트  3: 트리 \n";
	while (1) {
		cin >> select;
		if (select != 1 && select != 2 && select != 3)
		{
			cout << " 1, 2, 3 중에서 선택해주세요\n";
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

