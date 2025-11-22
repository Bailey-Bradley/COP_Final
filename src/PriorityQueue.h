#pragma once

#include <algorithm>
#include <list>

template<typename T, bool (&isLess)(T, T)>
class PriorityQueue {

    std::list<T> queue;

public:

    void enqueue(T);

    T min();

    T dequeue();
    void remove(T element);

    const std::list<T>& getQueue();
};

template<typename T, bool (&isLess)(T, T)>
void PriorityQueue<T, isLess>::enqueue(T newItem) {
    queue.push_back(newItem);
}

template<typename T, bool (&isLess)(T, T)>
T PriorityQueue<T, isLess>::min() {
    auto lowest_priority = std::min_element(queue.begin(), queue.end(), isLess);

    return *lowest_priority;
}

template<typename T, bool (&isLess)(T, T)>
T PriorityQueue<T, isLess>::dequeue() {
    T lowest_priority = min();
    queue.remove(lowest_priority);

    return lowest_priority;
}

template<typename T, bool (&isLess)(T, T)>
const std::list<T>& PriorityQueue<T, isLess>::getQueue() {
    return queue;
}

template<typename T, bool (&isLess)(T, T)>
void PriorityQueue<T, isLess>::remove(T element) {
    queue.remove(element);
}