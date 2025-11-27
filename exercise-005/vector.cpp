#include "vector.hpp"
#include <cstdio>
#include <cstdlib>

// Aufgabe 3 – Mini-Vector

static const size_t VECTOR_INITIAL_CAPACITY = 4;

void vector_init(Vector_t* vec) {
    if (vec == nullptr) {
        return;
    }
    vec->data = static_cast<unsigned int*>(
        std::malloc(VECTOR_INITIAL_CAPACITY * sizeof(unsigned int))
    );
    if (vec->data == nullptr) {
        vec->size = 0;
        vec->capacity = 0;
        return;
    }
    vec->size = 0;
    vec->capacity = VECTOR_INITIAL_CAPACITY;
}

void vector_clear(Vector_t* vec) {
    if (vec == nullptr) {
        return;
    }
    if (vec->data != nullptr) {
        std::free(vec->data);
        vec->data = nullptr;
    }
    vec->size = 0;
    vec->capacity = 0;
}

int vector_push_back(Vector_t* vec, unsigned int value) {
    if (vec == nullptr) {
        return 0;
    }

    if (vec->data == nullptr || vec->capacity == 0) {
        vector_init(vec);
        if (vec->data == nullptr) {
            return 0;
        }
    }

    if (vec->size >= vec->capacity) {
        size_t newCapacity = vec->capacity * 2;
        unsigned int* newData = static_cast<unsigned int*>(
            std::realloc(vec->data, newCapacity * sizeof(unsigned int))
        );
        if (newData == nullptr) {
            return 0;
        }
        vec->data = newData;
        vec->capacity = newCapacity;
    }

    vec->data[vec->size] = value;
    vec->size++;
    return 1;
}

int vector_get(const Vector_t* vec, size_t index, unsigned int* outValue) {
    if (vec == nullptr || outValue == nullptr) {
        return 0;
    }
    if (index >= vec->size) {
        return 0;
    }
    *outValue = vec->data[index];
    return 1;
}

void vector_print(const Vector_t* vec) {
    if (vec == nullptr || vec->data == nullptr) {
        std::printf("[]\n");
        return;
    }

    std::printf("[");
    for (size_t i = 0; i < vec->size; ++i) {
        std::printf("%u", vec->data[i]);
        if (i + 1 < vec->size) {
            std::printf(", ");
        }
    }
    std::printf("]\n");
}
