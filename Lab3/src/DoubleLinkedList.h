//
// Created by Jenya on 20.11.2024.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <assert.h>
#include <stdexcept>

template<typename T>
class DoubleLinkedList
{
public:
	struct Node
	{
		T Value;
		Node* Next;
		Node* Previous;

		explicit Node(const T& value) : Value(value), Next(nullptr), Previous(nullptr) {}
	};

private:
	Node* _head;
	Node* _tail;
	int _count;

public:
	DoubleLinkedList() : _head(nullptr), _tail(nullptr), _count(0) {}

	Node* InsertAfter(T&& value, Node* node = nullptr);
	Node* InsertBefore(T&& value, Node* node = nullptr);
	Node* Find(const T& value) const;
	void Remove(Node* node);
	void AssertNoLoops() const;

	[[nodiscard]] int GetCount() const { return _count; }
	Node* GetHead() { return _head; }
	Node* GetTail() { return _tail; }
};

template<typename T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::InsertAfter(T&& value, Node* node)
{
	Node* newNode = new Node(std::forward<T>(value));
	if (_head == nullptr)
		_head = newNode;

	if (node == nullptr)
	{
		if (_tail != nullptr)
		{
			_tail->Next = newNode;
			newNode->Previous = _tail;
		}
	}
	else
	{
		if (auto nextNode = node->Next; nextNode != nullptr)
		{
			nextNode->Previous = newNode;
			newNode->Next = nextNode;
		}

		node->Next = newNode;
		newNode->Previous = node;
	}

	if (node == _tail)
		_tail = newNode;

	_count++;
	return newNode;
}

template<typename T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::InsertBefore(T&& value, Node* node)
{
	Node* newNode = new Node(std::forward<T>(value));
	if (_head == nullptr)
		_head = newNode;

	if (node == nullptr)
	{
		if (_head != nullptr)
		{
			_head->Previous = newNode;
			newNode->Next = _head;
		}
	}
	else
	{
		if (auto prevNode = node->Previous; prevNode != nullptr)
		{
			prevNode->Next = newNode;
			newNode->Previous = prevNode;
		}

		node->Previous = newNode;
		newNode->Next = node;
	}

	if (node == _head)
		_head = newNode;

	_count++;
	return newNode;
}

template<typename T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::Find(const T& value) const
{
	if (_head == nullptr)
		return nullptr;

	Node* current = _head;
	while (current != nullptr)
	{
		if (current->Value == value)
			return current;

		current = current->Next;
	}

	return nullptr;
}

template<typename T>
void DoubleLinkedList<T>::Remove(Node* node)
{
	assert(_head != nullptr);
	assert(node != nullptr);

	if (node == _head)
	{
		if (node->Next != nullptr)
			_head = node->Next;
	}
	if (node == _tail)
	{
		if (node->Previous != nullptr)
			_tail = node->Previous;
	}

	Node* nextNode = node->Next;
	Node* previousNode = node->Previous;

	if (previousNode != nullptr)
		previousNode->Next = nextNode;
	if (nextNode != nullptr)
		nextNode->Previous = previousNode;

	_count--;
	delete node;
}

template<typename T>
void DoubleLinkedList<T>::AssertNoLoops() const
{
	if (_head == nullptr)
		return;

	Node* current = _head;
	int count = 0;
	while (current != nullptr)
	{
		count++;
		assert(count <= _count);
		current = current->Next;
	}
}

#endif //DOUBLELINKEDLIST_H
