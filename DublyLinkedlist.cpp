#include "DS.h"

//������ȣ 3045�� ���� ���Ḯ��Ʈ
//��� �߰�


void linkedlist(void) {
	int select = 0;

	//Ŭ���� ����
	Linkedlist L;

	while (1)
	{
		cout << "����:1  �˻�:2  ���:3  ����:4\n";

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
			cout << "�����մϴ�.\n";
			break;

		default:
			cout << "1,2,3,4 �߿��� ����\n";
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

	Node_list* head = new Node_list; //��� ��� ����

	for (int i = 1; i < Node; i++)
	{
		insertFront(&head, i); //�ʿ��� ��� ���̱�
	}

	while (Count--) {
		cin >> cmd >> node_move >> node_fix;


	}
	

	return 0;
}
*/