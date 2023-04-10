#include <iostream>

using namespace std;

//template <typename T>

int main(void) {

	int n_of_nodes = 0; //노드 개수

	cin >> n_of_nodes;
	
	int* node_list = new int[n_of_nodes-1]; //2~마지막 노드까지 생성

	for (int i = 0; i < n_of_nodes - 1; i++) //전체 배열 사이즈가 n -1 임
	{
		node_list[i] = 0; //초기화
	}

	int node1 = 0, node2 = 0; //연결된 두 노드

	int index = n_of_nodes; //while문 조건

	while (index > 1) {

		cin >> node1 >> node2; //노드 2개 입력
		if (node_list[max(node1, node2) - 2] == 0) {

			node_list[max(node1, node2) - 2] = min(node1, node2); 
			// 2~마지막 노드에 대하여 자식 노드의 위치에 부모 노드를 저장

		}
		else
		{
			node_list[min(node1, node2) - 2] = max(node1, node2);
		}
		

		index--;
	}
	
	for (int i=0; i < n_of_nodes-1; i++)
	{
		cout << node_list[i] << "\n";
	}

	return 0;
}