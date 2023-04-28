#pragma once
#include <iostream>

using namespace std;

class Node {
protected:
	int data = -999;
	Node* head = NULL;
	Node* tail = NULL;

public:
	int value = 0;
	Node* left = NULL;
	Node* right = NULL;

	//������
	Node() {}
	//�Ҹ���
	~Node() {}

	int get() {
		return data;
	}

	void change(int element) {
		data = element;
	}

	Node* front() {
		return head;
	}

	void front(Node* newnode) {
		head = newnode;
	}

	Node* back(void) {
		return tail;
	}

	void back(Node* newnode) {
		tail = newnode;
	}

};

/*//////////////////////////////////////////////*/

class Stack{
private:
	int top_id = -1;

public:
	int element = 0;


	//�迭 ����
	Node* Stack_list = new Node[100];

	void push() {
		cout << "�߰��� �����͸� �Է����ּ���: ";
		cin >> element;
		Stack_list[++top_id].change(element);
	}

	void pop() {
		if (top_id < 0)
			cout << "������ �������" << "\n";
		else
		{
			cout << Stack_list[top_id--].get() << "\n";
		}
	}

	void show() {
		for (int i = 0; i <= top_id; i++)
			cout << Stack_list[i].get() << " ";
		cout << "\n";
	}

	//memory return
	~Stack()
	{
		delete[] Stack_list;
	}

};
/*///////////////////////////////////////////////////*/

class Linkedlist{
protected:
	Node* first = NULL;

public:
	int element=0;

	Linkedlist() {}

	void insert() {

		cout << "�߰��� �����͸� �Է����ּ���: ";
		cin >> element;

		Node* New = new Node[1];
		New->change(element); //New data�� element �Է�

		Node* find = first;

		//first�� NULL�� ��,
		if (first == NULL)
			first = New;
		
		else
		{
			//�� ������ �̵�
			while (find->back() != NULL)
				find = find->back();

			//���� ����
			New->front(find); //New�� head ����
			find->back(New); //find�� tail ����
		}
	}

	void search() {
		int num = 1;

		cout << "�˻��� �����͸� �Է����ּ���: ";
		cin >> element;
		Node* find = first;

		//element�� �ִ� ������ �̵�
		while (first != NULL && find->get() != element && find->back() != NULL)
		{
			find = find->back();
			num++;
		}

		//����Ʈ�� ������� Ȯ��
		if (first == NULL)
			cout << "����Ʈ�� �������\n";

		//������ ��� Ȯ��
		else if (find->get() != element)
			cout << "�ش� ���� ����Ʈ�� �����ϴ�.\n";
		else
			cout << num << "��° ��忡 " << element << "������\n";

	}

	void show() {
		Node* find = first;
		cout << "���� ����Ʈ\n";

		while (find != NULL && find->get() != 999)
		{
			cout << find->get() << " ";
			find = find->back();
		}
		if (first == NULL)
			cout << "����Ʈ�� ��� ����\n";
		else cout << "\n";

	}

	~Linkedlist() {

		Node* find = first;

		//������ �̵�
		while (first && find->back() != NULL)
			find = find->back();

		//������ �̵��ϸ鼭 ����
		while (find != first)
		{
			Node* Del = NULL; //���� ��� �����
			find = find->front(); //find ������ �̵�
			Del = find->back(); //Del�� ���� ��� ���
			find->back(NULL); //tail ����

			delete[] Del; //��� ����
		}

		//find == first�̸� �� �� ����
		delete[] find, first;
	}

};


//�Լ� ����
void stack();
void linkedlist();
void binary_tree();