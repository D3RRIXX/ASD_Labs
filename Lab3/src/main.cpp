#include <iostream>

#include "LinkedList.h"

int main()
{
    auto list = LinkedList<int>();
    list.InsertAfter(15);
    const auto node = list.InsertAfter(20);
    const auto after = list.InsertAfter(30, node);
    list.InsertAfter(40, node);
    list.RemoveAfter(after);

    auto current = list.GetHead();
    while (current != nullptr)
    {
        std::cout << current->Value << std::endl;
        current = current->Next;
    }
}
