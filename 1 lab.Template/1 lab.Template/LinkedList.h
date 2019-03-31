#pragma once
#include <iostream>
#include "Iterator.h"

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
	size_t size;
	Node *head;
	Node *tail;
	
class ListIterator : public Iterator<T>
	{
	public:
		ListIterator(Node *head) { current = head; };
	private:
		T next() override;
		bool has_next() override;
		Node* current;
	};

	Iterator<T>* create_list_iterator();
	friend std::ostream& operator<<(std::ostream& os, LinkedList<T>& linked_list) {
		if (linked_list.size == 0)
			return os << "[nullptr]";
		auto* list = linked_list.create_list_iterator();
		os << "[nullptr] <-> ";
		while (list->has_next()) {
			os << "[" << list->next() << "] <-> ";
		}
		os << "[nullptr]" << std::endl;
		return os;
	};
	
public:
	LinkedList();
	~LinkedList();
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
