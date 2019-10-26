#include "node.h"


template<class T>
Node<T>::Node(T o) : obj(o), next_Node(nullptr)
{
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
Node<T>* Node<T>::next()
{
	return next_Node;
}

template<class T>
T Node<T>::get_Obj()
{
	return obj;
}
