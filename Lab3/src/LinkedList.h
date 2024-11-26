//
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
		Node* Next;

		explicit Node(T value) : Value(value), Next(nullptr) {}
	};

	struct FindNodeResult
	{
		Node* TargetNode = nullptr;
		Node* ParentNode = nullptr;

		FindNodeResult() : TargetNode(nullptr), ParentNode(nullptr) {}
		FindNodeResult(Node* targetNode, Node* parentNode) : TargetNode(targetNode), ParentNode(parentNode) {}
	};

private:
	Node* _head = nullptr;
	int _count = 0;

public:
	Node* InsertAfter(T&& value, Node* node = nullptr);
	void RemoveAfter(Node* node);
	void AssertNoLoops() const;
	FindNodeResult Find(T value) const;

	Node* GetHead() const { return _head; }
	[[nodiscard]] int GetCount() const { return _count; }
};

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::InsertAfter(T&& value, Node* node)
{
	auto newNode = new Node(std::forward<T>(value));
	value = T();
	_count++;

	if (node != nullptr)
	{
		node->Next = newNode;
	}
	else
	{
		if (_head != nullptr)
			newNode->Next = _head;

		_head = newNode;
	}
	return newNode;
}

template<typename T>
void LinkedList<T>::RemoveAfter(Node* node)
{
	assert(_head != nullptr);

	Node* toRemove = node != nullptr ? node->Next : _head;
	if (toRemove == nullptr)
		return;

	_count--;

	if (node != nullptr)
		node->Next = toRemove->Next;
	else
		_head = toRemove->Next;

	delete toRemove;
}

template<typename T>
void LinkedList<T>::AssertNoLoops() const
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

template<typename T>
typename LinkedList<T>::FindNodeResult LinkedList<T>::Find(T value) const
{
	if (_head == nullptr)
		return FindNodeResult();

	if (_head->Value == value)
		return FindNodeResult(_head, nullptr);

	Node* current = _head;
	while (current->Next != nullptr)
	{
		if (Node* next = current->Next; next->Value == value)
			return FindNodeResult(next, current);

		current = current->Next;
	}

	return FindNodeResult();
}


#endif //LINKEDLIST_H
