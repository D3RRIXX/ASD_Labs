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
		Node* Next = nullptr;

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

public:
	Node* InsertAfter(T value, Node* node = nullptr);
	void RemoveAfter(Node* node);
	void AssertNoLoops() const;
	FindNodeResult Find(T value) const;

	Node* GetHead() const { return _head; }
};

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::InsertAfter(T value, Node* node)
{
	auto newNode = new Node(value);

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

template<typename T>
void LinkedList<T>::AssertNoLoops() const
{
	if (_head == nullptr)
		return;

	Node* slow = _head;
	Node* fast = _head;

	while (fast != nullptr && fast->Next != nullptr)
	{
		slow = slow->Next;
		fast = fast->Next;

		if (slow == fast)
			throw std::runtime_error("LinkedList::AssertNoLoops: Loop Detected");
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
