#include "Graph.h"

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    // Get node corresponding to "startLabel". This will be called "current_node"
    // Get all of its edges
    // For every node opposite of current_node, construct a "path" object
        // The path object will be a lightweight object consisting of a pointer to an element, a pointer to the path object for the node before it, and a cost
    // For every constructed path object, add it to a priority queue if:
        // There is no path object for the node that this path object refers to that is already in the priority queue
        // OR
        // There's already a path object to this node in the priority queue, but its cumulative cost is higher (this path object then replaces that one)
    // Search through the priority queue of paths and select the least costly one

    // Repeat until the goal node has been "processed". That is, all edges leading to the goal have been considered.

    // IDK theres some problems in the above algorithm that I can already see but this is a start.
}