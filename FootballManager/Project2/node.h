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

private:
	Node* next_Node;
	T obj;
};