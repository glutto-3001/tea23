#include <fmt/chrono.h>
#include <fmt/format.h>
#include "graveyard.h"

/* .bss Segment */
int foo;
int foo2 = 0;

/* .data Segment */
int data = 45;
int data2 = 43;

/* .rodata Segment */
const int rodata = 45;
const int rodata2 = 43;


void graveyard();

void doSomething(int value)
{
    value = value + 1;
    fmt::print("doSomething, value {}\n", value);
}

void doSomethingPtr(int* ptr)
{
    *ptr = *ptr + 1;
    fmt::print("doSomethingPtr, value {}\n", *ptr);
}

int* doReturnAPtr()
{
    int value = 4711;
    fmt::print("doReturnAPtr, value {}\n", value);
    return &value;
}

void doSomethingStatic()
{
    static int value = 56;
    value = value + 1;
    fmt::print("doSomethingStatic, value {}\n", value);
}


 //int undead = 7;

auto main(int argc, char** argv) -> int
{


    /* ------ Aufgabe 1:------  
            
        1. a)
        2. b)
        3. a)
        4. a) 
       ---- Ende Aufgabe 1 ---- 
        */

    /* ------ Aufgabe 2:------  

        Bsp 1:
            #include <fmt/format.h>
            #include <cstdlib>
            #include <cstring>

            #define SOULS 100

            void cursed() {
                char *soul = (char*)malloc(8);
                strcpy(soul, "boo!");
                fmt::println("{}", soul);
                

                free(soul); <------- hier her

                Problem: Der Speicher wir nicht wieder freigegeben, dadurch wird mit jedem Aufruf von cursed() mehr Speicher belegt bis kein Speicher mehr verfügbar ist.
                Lösung:  Speicher mit free() wieder freigeben.
            }

            int main() {
                for(int i=0; i < SOULS; i++) {
                    cursed();
                }
            }

        Bsp 2:
            #include <fmt/format.h>
            #include <cstdlib>
            #include <cstring>

            int main() {
                char *ghost = (char*)malloc(8);
                strcpy(ghost, "evil");
                free(ghost);
                fmt::println("{}", ghost);
            }

            Da nach dem Freigeben des Speichers wieder auf diesen zugegriffen wird, kommt es zu einem undefinierten Verhalten des Speichers.
            Wird danach erneut Speicher allokiert, zeigt der dazugehörige Pointer evtl. den alten Wert des Speichers an, kann aber auch vom vorigen Wert abweichen.

        Bsp 3:
            #include <cstdlib>

            int main() {
                while (1) {
                    malloc(1024);
                }
            }

        Durch das andauernde Allokieren von Speicher ohne diesen wieder freizugeben, wird irgendwann kein Speicher mehr verfügbar sein und das Programm wird abstürzen (Stack-Overflow).
       ---- Ende Aufgabe 2 ---- 
       */
      
      /* ------ Aufgabe 3:------
      


      ---- Ende Aufgabe 3 ----
        */ 
       
       /* ------ Aufgabe 4:------
       
       1. Ein Stack Overflow entsteht, wenn zu viel Speicher auf dem Stack allokiert wird. Der Stack hat eine begrenzte Größe, und wenn diese überschritten wird, kann das Programm abstürzen oder unerwartetes Verhalten zeigen. Dies kann durch tiefe Rekursionen oder das Allokieren großer Datenstrukturen auf dem Stack verursacht werden.
       2. Memory Leaks entstehen, wenn Speicher allokiert wird und nicht mehr freigegeben wird.
       3. Der Zombie Pointer ist gefährlicher, da er auf evtl. bereits geänderten Speicher zeigt und somit zu undefiniertem Verhalten führen kann, während ein Memory Leak "nur" dazu führt, dass Speicher nicht mehr verfügbar ist.
       4. Man kann solche Fehler frühzeitig erkennen, indem man Speichertools
       
       ---- Ende Aufgabe 4 ----
       */ 
      
      /* ------ Aufgabe 5:------
      
        Siehe graveyard.cpp und graveyard.h

      ---- Ende Aufgabe 5 ----
        */ 
      
      /* ------ Aufgabe 6:------
      


      ---- Ende Aufgabe 6 ----
        */ 
      

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    
    
    /* fmt::print("Hello, {}!\n", argv[0]);

    doSomething(42);
    int bar = 42;
    doSomething(bar);
    fmt::print("The value of bar is: {}\n", bar);

    doSomethingPtr(&bar);
    fmt::print("The value of bar after doSomethingPtr is: {}\n", bar);

    int* returnedPtr = doReturnAPtr();
    fmt::print("The value of returnedPtr content  after doReturnAPtr is: {}\n", *returnedPtr);
    doSomething(42);
    fmt::print("The value of returnedPtr content  after doReturnAPtr is: {}\n", *returnedPtr);

    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();

    fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo));
    fmt::print("Value of foo2 {} address of foo2 {}\n", foo2, fmt::ptr(&foo2));
    fmt::print("Value of data {} address of data {}\n", data, fmt::ptr(&data));
    fmt::print("Value of data2 {} address of data2 {}\n", data2, fmt::ptr(&data2));
    fmt::print("Value of rodata {} address of rodata {}\n", rodata, fmt::ptr(&rodata));
    fmt::print("Value of rodata2 {} address of rodata2 {}\n", rodata2, fmt::ptr(&rodata2));

    int var;
    static int var2;
    fmt::print("Value of var {} address of var {}\n", var, fmt::ptr(&var));
    fmt::print("Value of var2 {} address of var2 {}\n", var2, fmt::ptr(&var2));


    

    return 0; /* exit gracefully*/ 

    fmt::println("🪦 Globale Variable sagt: {}", undead);
    awaken();
    persistent();
    persistent();
    fmt::println("🪦 Globale Variable nach Aufruf: {}", undead);
}

