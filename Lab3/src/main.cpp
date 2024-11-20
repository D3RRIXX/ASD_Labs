#include <iostream>

#include "LinkedList.h"

int main()
{
    auto list = LinkedList<int>();
    list.InsertAfter(15);
    const auto node = list.InsertAfter(20);
    list.InsertAfter(40, node);

    auto findNodeResult = list.Find(15);
}
