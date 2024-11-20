﻿//
// Created by Jenya on 20.11.2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>

template<typename T>
class LinkedList
{
public:
	struct Node
	{
		T Value;
		Node* Next = nullptr;
	};

private:
	Node* _head = nullptr;

public:
	Node* InsertAfter(T value, Node* node = nullptr);
	void RemoveAfter(Node* node);
	void AssertNoLoops() const;

	Node* GetHead() const { return _head; }
};

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::InsertAfter(T value, Node* node)
{
	auto newNode = new Node();
	newNode->Value = value;

	if (node == nullptr)
	{
		if (_head != nullptr)
			newNode->Next = _head;

		_head = newNode;
		return newNode;
	}

	Node* current = _head;
	while (current->Next != nullptr)
	{
		if (current == node)
		{
			newNode->Next = current->Next;
			current->Next = newNode;
			return newNode;
		}

		current = current->Next;
	}

	throw std::runtime_error("LinkedList::InsertAfter: Node not found");
}

template<typename T>
void LinkedList<T>::RemoveAfter(Node* node)
{
	Node* current = node->Next;
	while (current != nullptr)
	{
		Node* next = current->Next;
		delete current;
		current = next;
	}

	node->Next = nullptr;
}


#endif //LINKEDLIST_H