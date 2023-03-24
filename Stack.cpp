#include <iostream>
#include <string.h>
#include <vector>
#include <cstring>

using namespace std;

class Stack {
private:
	int top_id = -1;
	vector <int>stack_list;

public:

	//배열 생성
	int* new_stack(int top_id) {
		int* stack = new int[(top_id + 1) * sizeof(int)];
		return stack;
	}

	void push(int x) {

		//메모리 추가
		stack_list.reserve((++top_id + 1) * sizeof(int));

		//정수 할당
		stack_list.emplace_back(x);

	}

	void pop() {
		if (top_id < 0)
			cout << -1<<endl;
		else
		{
			cout << stack_list.back() << endl;
			stack_list.pop_back(); //마지막 값 제거
			stack_list.shrink_to_fit(); //빈 공간 제거
			top_id--;
		}
	}

	void size() {
		cout << stack_list.size() << endl;
	}

	void empty() {
		if (top_id < 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	void top() {
		if (top_id < 0)
			cout << -1 << endl;
		else
			cout << stack_list.back() << endl;
	}

};
/* *************************************************/

int main(void) {
	//class 생성
	Stack S;

	//var 생성
	int count = 0;
	char cmd[20] = { 0 };
	char* cp = cmd;
	int x = 0;
	int num = 0;

	//명령 횟수 입력
	cin >> count;

	for (int c = 0; c < count; c++)
	{
		//var 입력
		cin >> cmd;

		//명령 분류
		if (strstr(cp, "push") != nullptr)
		{
			cin >> num;
			x = num;
			S.push(x);
		}
		else if (strstr(cp, "pop") != nullptr)
			S.pop();
		else if (strstr(cp, "size") != nullptr)
			S.size();
		else if (strstr(cp, "empty") != nullptr)
			S.empty();
		else if (strstr(cp, "top") != nullptr)
			S.top();
		else
			cout << "input error!" << endl;

		//cmd 초기화
		strcpy_s(cmd,20,"");
	}
	return 0;
}

/*push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.*/