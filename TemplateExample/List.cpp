//g++ -std=c++14 List.cpp -o main
#include <iostream>
using namespace std;

//'template' and 'typename' are key words
template <typename genDataType>
struct Node {
	genDataType data;
	struct Node *next;
};

template <typename genDataType>
class List
{
	Node<genDataType> *head;
	unsigned int numElements;
public:
	List()
	{
		this->head = nullptr;
		this->numElements = 0;
	}

	void insert(genDataType newData) {
		//make new node
		//for the assignment
		Node<genDataType>* newNode = new Node<genDataType>();
		newNode->data = newData;
		this->numElements++;
		newNode->next = nullptr;
		Node<genDataType>* headCopy = this->head;
		if(this->head == nullptr)
		{
			this->head = newNode;
		}
		else
		{
			while(headCopy->next != nullptr)
			{
				headCopy = headCopy->next;	
			}
			headCopy->next = newNode;
		}
		return;
	}

	void push_front(genDataType newData) {
		//make new node
		//for the assignment
		Node<genDataType>* newNode = new Node<genDataType>();
		newNode->data = newData;
		newNode->next = this->head;
		this->head = newNode;
		this->numElements++;
		return;
	}

	genDataType pop_front() {
		genDataType ret;
		Node<genDataType>* tempNode = this->head;
		ret = tempNode->data;
		this->head = this->head->next;
		this->numElements--;
		delete(tempNode);
		return ret;
	}

	void print()
	{
		if(this->head == nullptr)
		{
			return;
		}
		Node<genDataType>* headCopy = this->head;
		while(headCopy->next != nullptr)
		{
			cout << headCopy->data << " ";
			headCopy = headCopy->next;
		}
		cout << headCopy->data << endl;
	}

	unsigned int size()
	{
		return (this->numElements);
	}

	genDataType operator[](unsigned int idx)
	{
		genDataType ret;
		Node<genDataType>* headCopy = this->head;
		unsigned int idxCounter = 0;	
		while(headCopy != nullptr)
		{
			if(idxCounter == idx)
			{
				ret = headCopy->data;
				break;
			}
			idxCounter++;
			headCopy = headCopy->next;
		}
		return ret;
	}

	void clear()
	{
		Node<genDataType>* headCopy = this->head;
		Node<genDataType>* prevCopy;
		while(headCopy->next != nullptr)
		{
			prevCopy = headCopy;
			headCopy = headCopy->next;
			delete (prevCopy);
		}
		delete (headCopy);
		this->head = nullptr;	
		this->numElements = 0;
	} 

	~List()
	{
		if(this->head == nullptr)
		{
			return;
		}
		Node<genDataType>* headCopy = this->head;
		Node<genDataType>* prevCopy;
		while(headCopy->next != nullptr)
		{
			prevCopy = headCopy;
			headCopy = headCopy->next;
			delete (prevCopy);
		}
		delete (headCopy);
	}
};

int main()
{
	List<int> *intList;
	intList = new List<int>();
	cout << "Size of the intList is "<< intList->size() << endl;
	intList->insert(3);
	cout << "Size of the intList is "<< intList->size() << endl;
	intList->insert(5);
	cout << "Size of the intList is "<< intList->size() << endl;
	intList->insert(9);
	cout << "Size of the intList is "<< intList->size() << endl;
	intList->print();

	cout <<  "0th element of list is " << intList[0][0] << endl;
	cout <<  "1st element of list is " << intList[0][1] << endl;
	cout <<  "2nd element of list is " << intList[0][2] << endl;
	intList->clear();
	cout << "Size of the intList is "<< intList->size() << endl;
	intList->insert(20);
	intList->insert(21);
	intList->insert(25);
	intList->push_front(200);
	intList->print();
	intList->pop_front();
	intList->print();

	delete intList;

	List<float> *floatList;
	floatList = new List<float>();
	floatList->insert(3.7);
	floatList->insert(5.7);
	floatList->insert(5.9);
	floatList->insert(10.9);
	floatList->print();
	return 0;
}