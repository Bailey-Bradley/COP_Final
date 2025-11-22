#include <algorithm>

#include "PriorityQueue.h"

template <typename T, typename C>
void PriorityQueue<T, C>::enqueue(T newItem) {
    queue.push_back(newItem);
}

template <typename T, typename C>
T PriorityQueue<T, C>::min() {
    auto lowest_priority = std::min_element(queue.begin(), queue.end(), isLess);

    return *lowest_priority;
}

template <typename T, typename C>
T PriorityQueue<T, C>::dequeue() {
    T lowest_priority = min();
    queue.remove(lowest_priority);

    return *lowest_priority;
}

template<typename T, typename C>
const std::list<T>& PriorityQueue<T, C>::getQueue() {
    return queue;
}

template<typename T, typename C>
void PriorityQueue<T, C>::remove(T element) {
    queue.remove(element);
}