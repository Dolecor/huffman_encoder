#include "Header.h"


// Функция построения дерева кодов
Node* buildTree(priority_queue<Node*, vector<Node*>, cmpNode> priorQ)
{
	while (priorQ.size() != 1)
	{
		Node* tempLeftChild = priorQ.top();
		priorQ.pop();
		Node* tempRightChild = priorQ.top();
		priorQ.pop();
		Node* temp = new Node(tempLeftChild, tempRightChild);
		priorQ.push(temp);
	}

	return priorQ.top();
}