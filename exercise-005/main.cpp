#include <fmt/format.h>
#include "list.hpp"
#include "vector.hpp"

auto main(int argc, char** argv) -> int
{
    fmt::print("Hello, {}!\n", argv[0]);

    // Aufgabe 4.1 – Liste testen
    List_t* list = NewList();

    // 5 Knoten erzeugen und einfügen
    ListNode_t* n1 = NewListNode();
    ListNode_t* n2 = NewListNode();
    ListNode_t* n3 = NewListNode();
    ListNode_t* n4 = NewListNode();
    ListNode_t* n5 = NewListNode();

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;
    n5->data = 50;

    InsertIntoLinkedList(list, n1);
    InsertIntoLinkedList(list, n2);
    InsertIntoLinkedList(list, n3);
    InsertIntoLinkedList(list, n4);
    InsertIntoLinkedList(list, n5);

    // Einfügen nach dem zweiten Knoten (n2)
    ListNode_t* n_after = NewListNode();
    n_after->data = 25;
    InsertIntoLinkedListAfterNode(list, n2, n_after);

    // Ein bestimmtes Element entfernen, z.B. n3 (Wert 30)
    RemoveFromList(list, n3);

    // Traversieren und ausgeben
    fmt::print("Liste: ");
    for (ListNode_t* n = GetNext(list, nullptr); n != nullptr; n = GetNext(list, n)) {
        fmt::print("{} ", n->data);
    }
    fmt::print("\n");

    FreeList(list);

    // Aufgabe 4.2 – Vector testen
    Vector_t vec;
    vector_init(&vec);

    // Fünf Werte einfügen
    vector_push_back(&vec, 1);
    vector_push_back(&vec, 2);
    vector_push_back(&vec, 3);
    vector_push_back(&vec, 4);
    vector_push_back(&vec, 5);

    // Element an Index 2 ausgeben
    unsigned int value = 0;
    if (vector_get(&vec, 2, &value)) {
        fmt::print("Vector[2] = {}\n", value);
    } else {
        fmt::print("Vector[2] Zugriff fehlgeschlagen\n");
    }

    // Gesamten Vector ausgeben
    fmt::print("Vector: ");
    vector_print(&vec);

    vector_clear(&vec);

    return 0;
}
