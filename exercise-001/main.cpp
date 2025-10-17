#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"


int globalVar1 = 42; // Example global variable
int globalVar2 = 0; // Example global variable
int globalVar3 = NULL; // Example global variable
static int globalVar4 = 42; // Example global variable
const int globalVar5 = 67; // Example global variable


void foo() {

    fmt::println("Hello from Foo!");
}

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    
    /* INSERT YOUR CODE HERE */
    static int localVar1 = 100;
    const int localVar2 = 200;
    

    int* heapVar = new int(3);
    fmt::println("Der Wert von heapVar ist: {}, die Adresse von heapVar: {}", *heapVar, fmt::ptr(heapVar));
    
    fmt::println("Addresse von foo: {}", fmt::ptr(&foo));
    fmt::println("Der Wert von globalVar1 ist: {}, die Adresse von globalVar1: {}", globalVar1, fmt::ptr(&globalVar1));
    fmt::println("Der Wert von globalVar2 ist: {}, die Adresse von globalVar2: {}", globalVar2, fmt::ptr(&globalVar2));
    fmt::println("Der Wert von globalVar3 ist: {}, die Adresse von globalVar3: {}", globalVar3, fmt::ptr(&globalVar3));
    fmt::println("Der Wert von globalVar4 ist: {}, die Adresse von globalVar4: {}", globalVar4, fmt::ptr(&globalVar4));
    fmt::println("Der Wert von globalVar5 ist: {}, die Adresse von globalVar5: {}", globalVar5, fmt::ptr(&globalVar5));
    fmt::println("Der Wert von localVar1 ist: {}, die Adresse von localVar1: {}", localVar1, fmt::ptr(&localVar1));
    fmt::println("Der Wert von localVar2 ist: {}, die Adresse von localVar2: {}", localVar2, fmt::ptr(&localVar2));
    
    delete heapVar;

    // Global: nur const hat immer denselben Wert. Adressbereich bleibt gleich, aber Einzeladresse ändert sich -> Variablen werden in den Heap-Speicher geschrieben.
    // Local: Speicheradressen aller Variablen ändern sich vom ursprünglichen. -> Lokale Variablen werden im Stack-Speicher abgelegt.
    // Heap: Adresse liegt im Heap-Speicherbereich, ändert sich aber auch bei jedem Programmstart.
    // Foo liegt im selben Speicherbereich wie die globalen Variablen (Code-Segment).
    
    return 0; /* exit gracefully*/
}
