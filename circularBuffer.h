//
// Created by smaug on 04.09.22.
//

#ifndef CIRCULARBUFFER_CIRCULARBUFFER_H
#define CIRCULARBUFFER_CIRCULARBUFFER_H

#include <iostream>

template <typename T>
class circularBuffer {

public:

    typedef struct
    {
        T* start;
        T* end;
        T* currentPtr;
    } element;

    element* buf;

    explicit circularBuffer(const int& capacity);

    ~circularBuffer();

public:

    void push(const T & elem);

    void print();

};

template<typename T>
void circularBuffer<T>::print() {
    T* tmp = buf->start;
    while(tmp != buf->end)
    {
        std::cout << *tmp;
        tmp += 1;
    }
}

template<typename T>
void circularBuffer<T>::push(const T &elem) {
    if (buf == NULL) {std::cout << "buff is NULL";}

    *(buf->currentPtr) = elem;

    T *tmp = buf->currentPtr + 1;

    if (tmp >= buf->end) {tmp = buf->start;}

    buf->currentPtr = tmp;
}

template<typename T>
circularBuffer<T>::circularBuffer(const int &capacity) {

    T* mem = static_cast<T *>(malloc(capacity * sizeof(T)));

    if (mem == NULL) {std::cout << "buff is NULL";}

    buf = static_cast<element *>(malloc(sizeof(element)));

    if (buf == NULL) {free(mem); std::cout << "buff is NULL";;}


    buf->start = mem;
    buf->end = mem + capacity;
    buf->currentPtr = mem;

}

template<typename T>
circularBuffer<T>::~circularBuffer() {
    if (buf == NULL) {return;}

    free(buf->start);

    free(buf);
}


#endif //CIRCULARBUFFER_CIRCULARBUFFER_H
