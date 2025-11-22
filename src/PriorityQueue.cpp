#include <algorithm>

#include "PriorityQueue.h"

template <typename T, typename C>
void PriorityQueue<T, C>::enqueue(T newItem) {
    queue.push_back(newItem);
}

template <typename T, typename C>
T PriorityQueue<T, C>::dequeue() {
    auto lowest_priority = std::min_element(queue.begin(), queue.end(), isLess);

    return *lowest_priority;
}