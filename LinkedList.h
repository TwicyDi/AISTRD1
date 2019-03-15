#include <iostream>

template <typename T>
class LinkedList
{
private:
	class Node
	{
	public:
		Node(T data, Node *next = nullptr, Node * prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		};
		~Node() {
			next = nullptr;
			delete next;
			prev = nullptr;
			delete prev;
			data = {};
		}

		T data;
		Node *next;
		Node *prev;
	};
	void reset_list();

	Node *head;
	Node *tail;
	

public:
	LinkedList();
	~LinkedList();
	size_t size;
	void push_back(T newElem); //add a new element into the end of the list
	void push_front(T newElem); //add a new element into the beginning of the list
	void pop_back(); //delete the element from the end of the list
	void pop_front(); //delete the element from the beginning of the list 
	void insert(size_t index, T newElem); //add a new element into the list by index
	T at(size_t index); //get the element from list by index
	void remove(size_t index); //delete the element from list by index
	size_t get_size(); //get list size
	void clear();  //delete all elements from the list
	void set(size_t index, T newElem); //set new element to the list by index
	bool isEmpty(); //check list is empty
	void Print_List(); //show all elemets from list
};
