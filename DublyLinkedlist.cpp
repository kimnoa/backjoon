#include "DS.h"

//문제번호 3045번 이중 연결리스트
//노드 추가


void linkedlist(void) {
	int select = 0;

	//클래스 생성
	Linkedlist L;

	while (1)
	{
		cout << "삽입:1  검색:2  출력:3  종료:4\n";

		cin >> select;

		switch (select) {

		case 1:
			L.insert();
			continue;

		case 2:
			L.search();
			continue;

		case 3:
			L.show();
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























/*
int main(void) 
{
	
	int Node = 0, Count = 0;
	char cmd = '\0';
	int node_move = 0, node_fix = 0;

	cin >> Node >> Count;

	Node_list* head = new Node_list; //헤드 노드 생성

	for (int i = 1; i < Node; i++)
	{
		insertFront(&head, i); //필요한 노드 붙이기
	}

	while (Count--) {
		cin >> cmd >> node_move >> node_fix;


	}
	

	return 0;
}
*/