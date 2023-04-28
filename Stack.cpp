#include "DS.h"

using namespace std;


/* *************************************************/
void stack(void) {
	//class 생성
	Stack S;

	//var 생성
	int select = 0;

	while(1)
	{
		cout << "push:1  pop:2  show:3  종료:4\n";
		//명령 입력
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
			cout << "종료합니다.\n";
			break;

		default:
			cout << "1,2,3,4 중에서 선택\n";
		}
		break;
	}
}

/*push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.*/