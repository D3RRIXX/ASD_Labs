#include <iostream>

#include "DoubleLinkedList.h"
#include "LinkedList.h"

void TestLinkedList() {
    auto list = LinkedList<int>();
    list.InsertAfter(15);
    const auto node = list.InsertAfter(20);
    list.InsertAfter(40, node);

    auto findNodeResult = list.Find(15);
}

void TestDoubleLinkedList()
{
    auto list = DoubleLinkedList<int>();
    const auto node = list.InsertAfter(15);
    list.InsertBefore(10, node);
    list.InsertAfter(20, node);

    const auto toRemove = list.Find(10);
    list.Remove(toRemove);

    auto find = list.Find(10);
    std::cout << "Node successfully deleted: " << (find == nullptr) << '\n';
}

int main()
{
    // TestLinkedList();
    TestDoubleLinkedList();
}
