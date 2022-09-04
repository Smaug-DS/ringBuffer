#include "circularBuffer.h"

int main()
{

    circularBuffer<char> cb(5);

    cb.push('A');
    cb.push('B');
    cb.push('C');
    cb.push('D');
    cb.push('E');
    cb.push('F');

    cb.print();

    circularBuffer<int> cb1(5);

    cb1.push(1);
    cb1.push(2);
    cb1.push(3);
    cb1.push(4);
    cb1.push(5);
    cb1.push(6);
    cb1.push(7);

    cb1.print();

    return 0;
}
