#include <list>

template<typename T, typename C>
class PriorityQueue {

    std::list<T> queue;
    C isLess;

public:

    void enqueue(T);

    T min();

    T dequeue();
    void remove(T element);

    const std::list<T>& getQueue();
};