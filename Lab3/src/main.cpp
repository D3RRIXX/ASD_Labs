#include <iostream>

#include "DoubleLinkedList.h"
#include "LinkedList.h"

void TestLinkedList()
{
	LinkedList<int> list;

	// Вставка узлов
	LinkedList<int>::Node* n1 = list.InsertAfter(10);
	LinkedList<int>::Node* n2 = list.InsertAfter(20, n1);
	LinkedList<int>::Node* n3 = list.InsertAfter(30, n2);

	assert(list.GetHead() == n1);
	assert(list.GetCount() == 3);

	// Поиск узлов
	const LinkedList<int>::FindNodeResult result = list.Find(20);
	assert(result.ParentNode == n1);
	assert(result.TargetNode == n2);

	list.RemoveAfter(nullptr); // Удаление головы
	assert(list.GetHead() == n2);
	assert(list.GetCount() == 2);

	list.RemoveAfter(n2); // Удаление хвоста
	assert(list.GetCount() == 1);

	// Проверка на циклы
	list.AssertNoLoops();
}

void TestDoubleLinkedList()
{
	DoubleLinkedList<int> list;

	// Вставка узлов
	DoubleLinkedList<int>::Node* n1 = list.InsertAfter(10, nullptr);
	DoubleLinkedList<int>::Node* n2 = list.InsertAfter(20, n1);
	DoubleLinkedList<int>::Node* n3 = list.InsertBefore(15, n2);

	assert(list.GetHead() == n1);
	assert(list.GetTail() == n2);
	assert(list.GetCount() == 3);

	// Удаление узлов
	list.Remove(n2);
	assert(list.GetTail() == n3);
	assert(list.GetCount() == 2);

	// Проверка на циклы
	list.AssertNoLoops();
}

int main()
{
	TestLinkedList();
	TestDoubleLinkedList();

	return 0;
}
