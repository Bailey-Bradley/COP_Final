/*
PriorityQueue.h:

This file is simply a priority queue implementation
*/
#pragma once

#include <algorithm>
#include <list>

template<typename T, bool (&isLess)(T, T)>
class PriorityQueue {

    // Container holding queued objects
    std::list<T> queue;

public:

    void enqueue(T); // Inserts into queue

    T min(); // Returns smallest element

    T dequeue(); // Removes then returns smallest element

    void remove(T element); // Removes every single specific element

    int size(); // Provides number of elements

    const std::list<T>& getQueue() const;
};

template<typename T, bool (&isLess)(T, T)>
int PriorityQueue<T, isLess>::size() {
    return queue.size();
}

template<typename T, bool (&isLess)(T, T)>
void PriorityQueue<T, isLess>::enqueue(T newItem) {
    queue.push_back(newItem);
}

template<typename T, bool (&isLess)(T, T)>
T PriorityQueue<T, isLess>::min() {
    // Find element with the least priority
    auto lowest_priority = std::min_element(queue.begin(), queue.end(), isLess);

    return *lowest_priority;
}

template<typename T, bool (&isLess)(T, T)>
T PriorityQueue<T, isLess>::dequeue() {
    T lowest_priority = min(); // Obtain lowest priority element
    queue.remove(lowest_priority); // Remove all the same type of element

    return lowest_priority;
}

template<typename T, bool (&isLess)(T, T)>
const std::list<T>& PriorityQueue<T, isLess>::getQueue() const {
    return queue;
}

template<typename T, bool (&isLess)(T, T)>
void PriorityQueue<T, isLess>::remove(T element) {
    queue.remove(element); // Removes all of the same type of element
}