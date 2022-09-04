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

    circularBuffer(const int& capacity)
    {

        T* mem = static_cast<T *>(malloc(capacity * sizeof(T)));

        if (mem == NULL) {std::cout << "buff is NULL";}

        buf = static_cast<element *>(malloc(sizeof(element)));

        if (buf == NULL) {free(mem); std::cout << "buff is NULL";;}


        buf->start = mem;
        buf->end = mem + capacity;
        buf->currentPtr = mem;

    }

    ~circularBuffer()
    {
        if (buf == NULL) {return;}

        free(buf->start);

        free(buf);
    }

public:

    void push(const T & elem)
    {
        if (buf == NULL) {std::cout << "buff is NULL";}

        *(buf->currentPtr) = elem;

        T *tmp = buf->currentPtr + 1;

        if (tmp >= buf->end) {tmp = buf->start;}

        buf->currentPtr = tmp;
    }

    void print()
    {
        T* tmp = buf->start;
        while(tmp != buf->end)
        {
            std::cout << *tmp;
            tmp += 1;
        }
    }

};


#endif //CIRCULARBUFFER_CIRCULARBUFFER_H
