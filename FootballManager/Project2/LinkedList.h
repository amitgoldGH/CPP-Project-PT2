#pragma once
#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H
#include <iostream>

/*
template<class T>
struct node {
	node<T>* next;
	T data;
};
*/
template<class T>
class node
{
public:

	node<T>* next;
	T* data;
	node(node<T>* next, T* data) : next(next), data(data) {}
};

template<class T>
class LinkedList
{
public:
	node<T>* first;
	node<T>* last;

	LinkedList()
	{
		first = nullptr;
		last = nullptr;
	}
	~LinkedList()
	{
		node<T>* temp = first;
		node<T>* temp1;

		while (temp != nullptr)
		{
			temp1 = temp;
			temp = temp->next;
			delete temp1;
		}
	}
	void add(T& data)
	{
		if (first == nullptr)
		{
			// The list is empty
			first = new node<T>(nullptr, &data);
			/*
			first->data = data;
			first->next = nullptr;
			*/
			//last = first;
		}
		else
		{
			// The list isn't empty
			if (first != nullptr && last == nullptr)
			{
				// The list has one element
				last = new node<T>(nullptr, &data);
				/*
				last->data = data;
				last->next = nullptr;
				*/
				first->next = last;
			}
			else
			{
				// The list has more than one element
				last->next = new node<T>(nullptr, &data);
				/*
				last->next->data = data;
				last->next->next = nullptr;
				*/
				last = last->next;
			}
		}
	}
	void deleteNode(T& o)
	{
		node<T>* curr = this->first;
		if (curr->data == &o)
		{
			node<T>* temp = curr->next;
			delete curr;
			this->first = temp;
			return;
		}
		else if (curr != nullptr)
		{
			node<T>* temp = curr->next;
			while (temp != nullptr)
			{
				if (temp->data == &o)
				{
					curr->next = temp->next;
					delete temp;
					return;
				}
				else
				{
					curr = curr->next;
					temp = temp->next;
				}
			}
		}
	}
	void print()
	{
		node<T>* curr = this->first;
		while (curr != nullptr)
		{
			curr->data->show();
			curr = curr->next;
		}
	}
};

#endif //__LINKEDLIST_H