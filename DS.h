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

	//생성자
	Node() {}
	//소멸자
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


	//배열 생성
	Node* Stack_list = new Node[100];

	void push() {
		cout << "추가할 데이터를 입력해주세요: ";
		cin >> element;
		Stack_list[++top_id].change(element);
	}

	void pop() {
		if (top_id < 0)
			cout << "스택이 비어있음" << "\n";
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

		cout << "추가할 데이터를 입력해주세요: ";
		cin >> element;

		Node* New = new Node[1];
		New->change(element); //New data에 element 입력

		Node* find = first;

		//first가 NULL일 때,
		if (first == NULL)
			first = New;
		
		else
		{
			//끝 노드까지 이동
			while (find->back() != NULL)
				find = find->back();

			//끝에 연결
			New->front(find); //New에 head 연결
			find->back(New); //find의 tail 연결
		}
	}

	void search() {
		int num = 1;

		cout << "검색할 데이터를 입력해주세요: ";
		cin >> element;
		Node* find = first;

		//element가 있는 노드까지 이동
		while (first != NULL && find->get() != element && find->back() != NULL)
		{
			find = find->back();
			num++;
		}

		//리스트가 비었는지 확인
		if (first == NULL)
			cout << "리스트가 비어있음\n";

		//마지막 노드 확인
		else if (find->get() != element)
			cout << "해당 값이 리스트에 없습니다.\n";
		else
			cout << num << "번째 노드에 " << element << "존재함\n";

	}

	void show() {
		Node* find = first;
		cout << "현재 리스트\n";

		while (find != NULL && find->get() != 999)
		{
			cout << find->get() << " ";
			find = find->back();
		}
		if (first == NULL)
			cout << "리스트가 비어 있음\n";
		else cout << "\n";

	}

	~Linkedlist() {

		Node* find = first;

		//끝으로 이동
		while (first && find->back() != NULL)
			find = find->back();

		//앞으로 이동하면서 삭제
		while (find != first)
		{
			Node* Del = NULL; //지울 노드 저장용
			find = find->front(); //find 앞으로 이동
			Del = find->back(); //Del에 지울 노드 담기
			find->back(NULL); //tail 변경

			delete[] Del; //노드 삭제
		}

		//find == first이면 둘 다 삭제
		delete[] find, first;
	}

};


//함수 모음
void stack();
void linkedlist();
void binary_tree();