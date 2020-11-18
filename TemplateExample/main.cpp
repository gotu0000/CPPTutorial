//g++ -std=c++14 main.cpp -o main
#include <iostream>
using namespace std;

//'template' and 'typename' are key words
template <typename genDataType>
struct Node {
	genDataType data;
	struct Node *next;

	void insert(Node** head, genDataType newData) {
		//make new node
		//for the assignment
		Node* newNode = new Node();
		newNode->data = newData;
		newNode->next = nullptr;
		Node* headCopy = *head;

		if(*head == nullptr)
		{
			cout << "Inserting head node" << endl;
			*head = newNode;
		}
		else
		{
			cout << "Inserting next node" << endl;
			while(headCopy->next != nullptr)
			{
				headCopy = headCopy->next;	
			}
			headCopy->next = newNode;
		}
		return;
	}

	void print(Node* head)
	{
		if(head == nullptr)
		{
			return;
		}
		Node* headCopy = head;
		while(headCopy->next != nullptr)
		{
			cout << headCopy->data << " ";
			headCopy = headCopy->next;
		}
		cout << headCopy->data << endl;
	}

	void clear_memory(Node* head)
	{
		Node* headCopy = head;
		Node* prevCopy;
		while(headCopy->next != nullptr)
		{
			prevCopy = headCopy;
			headCopy = headCopy->next;
			free(prevCopy);
		}
		free(headCopy);
	}
};

int main()
{
	cout << "Example of Template" << endl;
	//Initialization
	Node<int> *headInt;
	Node<float> *headFloat;
	headInt = nullptr;
	headFloat = nullptr;

	headInt->insert(&headInt, 2);
	headInt->insert(&headInt, 3);
	headInt->insert(&headInt, 4);
	headInt->print(headInt);

	headFloat->insert(&headFloat, 2.4);
	headFloat->insert(&headFloat, 3.1);
	headFloat->insert(&headFloat, 4.5);
	headFloat->insert(&headFloat, 6.8);
	headFloat->print(headFloat);

	//clear memory before exiting
	headInt->clear_memory(headInt);
	headFloat->clear_memory(headFloat);
	return 0;
}