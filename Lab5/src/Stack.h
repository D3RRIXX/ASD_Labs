//
// Created by Jenya on 27.11.2024.
//

#ifndef STACK_H
#define STACK_H
#include <assert.h>
#include <utility>

template<typename T>
class Stack
{
	struct Node
	{
		Node* Prev;
		T Value;
	};

	int _size = 0;
	Node* _tail = nullptr;

public:
	[[nodiscard]] int GetSize() const { return _size; }
	[[nodiscard]] bool IsEmpty() const { return _size == 0; }

	void Push(T&& value);
	T Pop();
	bool TryPop(T& outValue);
};

template<typename T>
void Stack<T>::Push(T&& value)
{
	Node* newNode = new Node(std::forward<T>(value));

	if (_tail != nullptr)
		newNode->Prev = _tail;

	_tail = newNode;
	_size++;
}

template<typename T>
T Stack<T>::Pop()
{
	assert(!IsEmpty());

	Node* currentTail = _tail;
	T value = std::forward<T>(currentTail->Value);

	_tail = currentTail->Prev;

	delete currentTail;
	_size--;

	return value;
}

template<typename T>
bool Stack<T>::TryPop(T& outValue)
{
	if (IsEmpty())
		return false;

	outValue = Pop();
	return true;
}

#endif //STACK_H
