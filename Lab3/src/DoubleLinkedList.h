//
// Created by Jenya on 20.11.2024.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template<typename T>
class DoubleLinkedList
{
public:
	struct Node
	{
		T Value;
		Node* Next;
		Node* Previous;

		explicit Node(const T& value) : Value(value) {}
	};

private:
	Node* _head;
	Node* _tail;

public:
	DoubleLinkedList() : _head(nullptr), _tail(nullptr) {}

	Node* InsertAfter(const T& value, Node* node = nullptr);
};

template<typename T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::InsertAfter(const T& value, Node* node)
{
	
}

#endif //DOUBLELINKEDLIST_H
