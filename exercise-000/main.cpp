#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter (int val) {
    fmt::println("Wert ist: {}", val);
    val = val + 10;
    fmt::println("Wert ist: {}", val);
}

void changeValueByPointer (int* ptr) {

    fmt::println("Der Pointer zeigt auf den Wert: {}", *ptr);
    *ptr = 77;
    fmt::println("Der Pointer zeigt auf den Wert: {}", *ptr);
}

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    
    /* INSERT YOUR CODE HERE */

    fmt::print("Hello, {} in version {} !\n", tea::PROJECT_NAME, tea::PROJECT_VER);
    fmt::print("Argumente: {} \n", argc);

    for (int i = 0; i < argc; i++){
        fmt::print("Argument {}: {} \n", i+1, argv[i]);

    int foo = 10;
    int* ptr = &foo;
    *ptr=42;
    int bar =4711;
    ptr=&bar;
    *ptr = foo;
    fmt::println("Bar ist: {}", bar);
    fmt::println("Foo ist: {}, mit Adresse: {}", foo, *ptr);
    fmt::println("Der Pointer zeigt so: {}", fmt::ptr(ptr));

    double* Pi = new double(3.1415);
    fmt::println("Double ist: {}, mit Adresse {}", *Pi, fmt::ptr(Pi));
    delete(Pi);
    fmt::println("Double ist: {}, mit Adresse {}", *Pi, fmt::ptr(Pi));
    
    int val = 0;
    changeValueByParameter(val);
    fmt::println("Der wert ist: {}", val);
    changeValueByPointer(&val);
    fmt::println("Der wert ist: {}", val);
    
    return 0; /* exit gracefully*/
    }
}