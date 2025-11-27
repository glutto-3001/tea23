#include <fmt/chrono.h>
#include <fmt/format.h>
#include "list.hpp"
#include "vector.hpp"

auto main(int argc, char** argv) -> int
{
    fmt::print("Hello, {}!\n", argv[0]);

    // Aufgabe 2 Listeneinträge verwalten
    // Demo: verkettete Liste
    List_t* list = NewList();
    auto* n1 = NewListNode();
    auto* n2 = NewListNode();
    auto* n3 = NewListNode();
    n1->data = 1;
    n2->data = 2;
    n3->data = 3;

    InsertIntoLinkedList(list, n1);
    InsertIntoLinkedList(list, n2);
    InsertIntoLinkedList(list, n3);

    fmt::print("Liste: ");
    for (ListNode_t* n = GetNext(list, nullptr); n != nullptr; n = GetNext(list, n)) {
        fmt::print("{} ", n->data);
    }
    fmt::print("\n");

    FreeList(list);

    // Aufgabe 3 Vektor verwalten
    // Demo: Mini-Vector
    Vector_t v;
    vector_init(&v);
    for (unsigned int i = 0; i < 6; ++i) {
        vector_push_back(&v, i * 10);
    }
    fmt::print("Vector: ");
    vector_print(&v);
    vector_clear(&v);

    return 0; // *exit gracefully*
}
