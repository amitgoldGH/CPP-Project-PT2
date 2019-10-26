#pragma once
template<class T>
class Node 
{
public:
	Node(T o);
	~Node();
	Node* next();
	T get_Obj();
	void set_Next(Node* next);
	void print();
	void deleteNode(T o);

private:
	Node* next_Node;
	T obj;
};