
#ifndef DATA_STRUCTURES_IN_C___STACK_H
#define DATA_STRUCTURES_IN_C___STACK_H

#include <memory>
#include <cstring>

#endif //DATA_STRUCTURES_IN_C___STACK_H

namespace DSAcpp {
    template<typename T>
    struct Stack {
        T* data;
        size_t capacity;
        size_t size;

        explicit Stack(size_t _capacity) : capacity(_capacity), size(0), data(nullptr) {
            data = static_cast<T*>(malloc(capacity * sizeof(T)));
        }

        ~Stack() {
            free(data);
        }

        void push(T newData) {
            if (size == capacity) {
                capacity++;
                data = static_cast<T*>(realloc(data, sizeof(T) * capacity));
                data[size] = newData;
                size++;
            }
            else {
                data[size] = newData;
                size++;
            }
        }

        void resize() {

        }

        auto pop() {
            size--;
            T popped = data[size];
            data[capacity] = data[capacity + 1];
            return popped;
        }

        T operator [] (int index) {
            return data[index];
        }
    };
}