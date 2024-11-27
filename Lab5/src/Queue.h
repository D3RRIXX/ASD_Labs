//
// Created by Jenya on 27.11.2024.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <utility>

template<typename T>
class Queue
{
	struct Node
	{
		Node* Next;
		T Value;
	};

	int _size = 0;
	Node* _head = nullptr;

public:
	[[nodiscard]] int GetSize() const { return _size; }
	[[nodiscard]] bool IsEmpty() const { return _size == 0; }

	void Enqueue(T&& value);
	T Dequeue();
	T* Front();
	bool TryDequeue(T& outValue);
};

template<typename T>
void Queue<T>::Enqueue(T&& value)
{
	Node* newNode = new Node(std::forward<T>(value));
	if (_head == nullptr)
		_head = newNode;
	else
		_head->Next = newNode;

	_size++;
}

template<typename T>
T Queue<T>::Dequeue()
{
	assert(_head != nullptr);

	_size--;

	Node* currentHead = _head;
	T value = std::forward<T>(currentHead->Value);
	_head = currentHead->Next;

	delete currentHead;

	return value;
}

template<typename T>
T* Queue<T>::Front()
{
	return IsEmpty() ? nullptr : &_head->Value;
}

template<typename T>
bool Queue<T>::TryDequeue(T& outValue)
{
	if (IsEmpty())
		return false;

	outValue = Dequeue();
	return true;
}

#endif //QUEUE_H
