#include <iostream>

template<class T>
struct node {
	node<T>* next;
	T data;
};

template<class T>
class LinkedList
{
public:
	node<T>* first;
	node<T>* last;
	LinkedList<T>() {
		first = nullptr;
		last = nullptr;
	}

	void add(T data) {
		if (first == nullptr) {
			// The list is empty
			first = new node<T>;
			first->data = data;
			first->next = nullptr;
			//last = first;
		}
		else {
			// The list isn't empty
			if (first != nullptr && last == nullptr) {
				// The list has one element
				last = new node<T>;
				last->data = data;
				last->next = nullptr;
				first->next = last;
			}
			else {
				// The list has more than one element
				last->next = new node<T>;
				last->next->data = data;
				last->next->next = nullptr;
				last = last->next;
			}
		}
	}

	void deleteNode(T o)
	{
		node<T>* curr = this->first;
		while (curr->next != nullptr)
		{
			if (curr == o)
				curr = curr->next;
		}
	}

	void print() {
		node<T>* curr = this->first;
		while (curr->next != nullptr)
		{
			std::cout << curr->data;
		}
	}


};