#include <fmt/format.h>
#include <chrono>
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

    // Aufgabe 6 – Inserts vergleichen (Liste vs. Vector)
    using clock = std::chrono::high_resolution_clock;
    constexpr unsigned int N = 1500;

    // Liste: immer nach Kopf einfügen
    List_t* list_bench = NewList();
    ListNode_t* head = NewListNode();
    head->data = 0;
    InsertIntoLinkedList(list_bench, head);

    auto start_list = clock::now();
    for (unsigned int i = 1; i <= N; ++i) {
        ListNode_t* node = NewListNode();
        node->data = i;
        InsertIntoLinkedListAfterNode(list_bench, head, node);
    }
    auto end_list = clock::now();
    auto dur_list = std::chrono::duration_cast<std::chrono::microseconds>(end_list - start_list).count();

    fmt::print("Listen-Insert ({} Elemente nach Kopf): {} µs\n", N, dur_list);

    FreeList(list_bench);

    // Vector: immer an Position 0 einfügen (teuerster Fall)
    Vector_t vec_bench;
    vector_init(&vec_bench);

    auto start_vec = clock::now();
    for (unsigned int i = 0; i < N; ++i) {
        vector_insert_at(&vec_bench, 0, i);
    }
    auto end_vec = clock::now();
    auto dur_vec = std::chrono::duration_cast<std::chrono::microseconds>(end_vec - start_vec).count();

    fmt::print("Vector-Insert ({} Elemente an Index 0): {} µs\n", N, dur_vec);

    vector_clear(&vec_bench);
    vector_clear(&vec);

    return 0;
}