#include "DS.h"


class BinarySearchTree {
public:
	BinarySearchTree() :root(nullptr) {};
	~BinarySearchTree() {};

	void addNode(int value);
	bool searchValue(int value);
	void removeNode(int value);
	void show();

private:
	Node* root = NULL;
	Node* tail = NULL;

	void inOrder(Node* current)
	{
		if (current != nullptr)
		{
			inOrder(current->left);
			std::cout << current->value << std::endl;
			inOrder(current->right);
		}
	}

	Node* searchMaxNode(Node* node)
	{
		if (node == NULL)
		{
			return NULL;
		}
		while (node->right != NULL)
		{
			node = node->right;
		}
		return node;
	}
	Node* removeSequence(Node* node, int _value);
};

void BinarySearchTree::addNode(int value)
{
	Node* node = new Node();
	Node* tmpRoot = nullptr;

	node->value = value;
	if (root == nullptr)
	{
		root = node;
	}
	else
	{
		Node* ptr = root;
		while (ptr != nullptr)
		{
			tmpRoot = ptr;
			if (node->value < ptr->value)
			{
				ptr = ptr->left;
			}
			else
			{
				ptr = ptr->right;
			}
		}
		if (node->value < tmpRoot->value)
		{
			tmpRoot->left = node;
		}
		else
		{
			tmpRoot->right = node;
		}
	}
}

Node* BinarySearchTree::removeSequence(Node* node, int _value)
{
	if (node == nullptr)
	{
		return NULL;
	}
	else if (node->value > _value)
	{
		node->left = removeSequence(node->left, _value);
	}
	else if (node->value < _value)
	{
		node->right = removeSequence(node->right, _value);
	}
	else
	{
		Node* ptr = node;
		if (node->right == nullptr && node->left == nullptr)
		{
			delete node;
			node = nullptr;
		}
		else if (node->right == nullptr)
		{
			node = node->left;
			delete ptr;
		}
		else if (node->left == nullptr)
		{
			node = node->right;
			delete ptr;
		}
		else
		{
			ptr = searchMaxNode(node->left);
			node->value = ptr->value;
			node->left = removeSequence(node->left, ptr->value);
		}
	}
	return node;
}

void BinarySearchTree::removeNode(int value)
{
	Node* ptr = root;
	removeSequence(ptr, value);

	delete ptr;
}

bool BinarySearchTree::searchValue(int value)
{
	Node* ptr = root;
	//	Node* tmpRoot = nullptr;
	while (ptr != nullptr)
	{
		if (ptr->value == value)
		{
			std::cout << value << "Found" << std::endl;
			return true;
		}
		else if (ptr->value > value)
		{
			ptr = ptr->left;
		}
		else
		{
			ptr = ptr->right;
		}
	}
	std::cout << value << "not Found" << std::endl;
	return false;
}

void BinarySearchTree::show()
{
	inOrder(root);
}


void binary_tree(void) {
	int select = 0;
	int value = 0;

	//클래스 생성
	BinarySearchTree T;

	while (1)
	{
		cout << "삽입:1  검색:2  출력:3  삭제:4  종료:5\n";

		cin >> select;

		switch (select) {

		case 1:
			cout << "입력할 값: ";
			cin >> value;
			T.addNode(value);
			continue;

		case 2:
			cout << "검색할 값: ";
			cin >> value;
			T.searchValue(value);
			continue;

		case 3:
			cout << "현재 이진 트리\n";
			T.show();
			continue;

		case 4:
			cout << "삭제할 값: ";
			cin >> value;
			T.removeNode(value);
			continue;

		case 5:
			cout << "종료합니다.\n";
			break;

		default:
			cout << "1,2,3,4,5 중에서 선택\n";
		}
		break;
	}

}