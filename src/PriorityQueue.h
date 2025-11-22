#include <list>

template<typename T, typename C>
class PriorityQueue {

    std::list<T> queue;
    C isLess;

public:

    void enqueue(T);
    T dequeue();

};