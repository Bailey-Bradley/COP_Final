#include <iostream>
#include <vector>
#include "Graph.h"

// Tests that setup functions as intended
int main(int, char**){
    std::cout << "Test\n";

    // Testing shortest path cost
    Graph g;
    std::vector<std::string> path;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addEdge("A","B", 8); // Path cost from A to B
    g.addEdge("B","C", 2); // Path cost from B to C

    unsigned long cost = g.shortestPath("A", "C", path);
    std::cout << "Path from A to C costs: " << cost << std::endl;

    // Display path to user
    std::cout << "Chosen path: ";
    for (const std::string& vertex : path) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}