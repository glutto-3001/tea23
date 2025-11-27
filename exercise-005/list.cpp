#include "list.hpp"
#include <cstdlib>

// Aufgabe 2.1 – Knotenverwaltung

ListNode_t* NewListNode(void) {
    ListNode_t* node = static_cast<ListNode_t*>(std::malloc(sizeof(ListNode_t)));
    if (node == nullptr) {
        return nullptr;
    }
    node->data = 0;
    node->pNext = nullptr;
    return node;
}

void FreeListNode(ListNode_t* elem) {
    if (elem != nullptr) {
        std::free(elem);
    }
}

// Aufgabe 2.2 – Listenverwaltung

List_t* NewList(void) {
    List_t* list = static_cast<List_t*>(std::malloc(sizeof(List_t)));
    if (list == nullptr) {
        return nullptr;
    }
    list->pHead = nullptr;
    list->pTail = nullptr;
    list->size  = 0;
    return list;
}

void FreeList(List_t* list) {
    if (list == nullptr) {
        return;
    }

    ListNode_t* current = list->pHead;
    while (current != nullptr) {
        ListNode_t* next = current->pNext;
        FreeListNode(current);
        current = next;
    }

    std::free(list);
}

// Aufgabe 2.3 – Einfügen

int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
    if (list == nullptr || elem == nullptr) {
        return 0;
    }

    elem->pNext = nullptr;

    if (list->pHead == nullptr) {            // leere Liste
        list->pHead = elem;
        list->pTail = elem;
    } else {                                 // nicht leere Liste
        list->pTail->pNext = elem;
        list->pTail = elem;
    }

    list->size++;
    return 1;
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node, ListNode_t* elem) {
    if (list == nullptr || node == nullptr || elem == nullptr) {
        return 0;
    }

    elem->pNext = node->pNext;
    node->pNext = elem;

    if (node == list->pTail) {
        list->pTail = elem;
    }

    list->size++;
    return 1;
}

// Aufgabe 2.4 – Entfernen

int RemoveFromList(List_t* list, ListNode_t* elem) {
    if (list == nullptr || elem == nullptr) {
        return 0;
    }

    ListNode_t* prev = nullptr;
    ListNode_t* cur  = list->pHead;

    while (cur != nullptr && cur != elem) {
        prev = cur;
        cur  = cur->pNext;
    }

    if (cur == nullptr) {        // nicht gefunden
        return 0;
    }

    if (cur == list->pHead) {    // Element ist Kopf
        list->pHead = cur->pNext;
    } else {
        prev->pNext = cur->pNext;
    }

    if (cur == list->pTail) {    // Element ist Ende
        list->pTail = prev;
    }

    FreeListNode(cur);
    list->size--;

    return 1;
}

// Aufgabe 2.5 – Traversieren

ListNode_t* GetNext(const List_t* list, ListNode_t* elem) {
    if (list == nullptr) {
        return nullptr;
    }

    if (elem == nullptr) {
        return list->pHead;
    }

    return elem->pNext;
}
