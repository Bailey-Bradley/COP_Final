/*
Vertex.cpp

Implements vertex class used in graph data structure
*/

#include "Vertex.h"
#include "Edge.h"

// Return vertex label to avoid repeats
const std::string& Vertex::getLabel() { return label; }

const PriorityQueue<Edge*, isLessPriority>& Vertex::getEdges() {
    return edges; // Returns priority queue of identified edges
}

// Locates edge connecting adjacent vertices
Edge* Vertex::getEdge(std::string label) {
    const std::list<Edge*> edge_list = edges.getQueue(); // Copies edges from priority queue

    // Loop to iterate over all edges that are incident
    for (Edge* edge : edge_list) {
        Vertex& adjacent = *edge->getOpposite(this); // Identified adjacent vertex

        if (adjacent.label == label) { // Condition to find matching edge
            return edge;
        }
    }

    return nullptr; // No edge found
}

// Overload finds adjacent vertices
Edge* Vertex::getEdge(const Vertex& vertex) {
    const std::list<Edge*> edge_list = edges.getQueue();

    for (Edge* edge : edge_list) {
        Vertex& adjacent = *edge->getOpposite(this);

        if (adjacent.label == vertex.label) {
            return edge;
        }
    }

    return nullptr;
}

// Add an incident edge to this vertex
void Vertex::addEdge(Edge* edge) {
    edges.enqueue(edge);
}

// Remove incident edge
void Vertex::removeEdge(Edge* edge) {
    edges.remove(edge);
}

bool Vertex::isAdjacentTo(const Vertex& vertex) {
    // See if the vertex shares any edges
    const std::list<Edge*> edge_list = edges.getQueue();

    for (Edge* edge : edge_list) {
        Vertex* adjacent = edge->getOpposite(this);

        if (adjacent == &vertex) {
            return true;
        }
    }

    return false;
}

// Uses a constructor to create an invalid vertex
Vertex::Vertex() : label("INVALID"), edges(PriorityQueue<Edge*, isLessPriority>()) {}

// Create a labeled vertex
Vertex::Vertex(std::string label) : label(label), edges(PriorityQueue<Edge*, isLessPriority>()) {}

// Uses a destructor to delete all edges that are incident
Vertex::~Vertex() {
    const std::list<Edge*> edge_list = edges.getQueue();

    for (Edge* edge : edge_list) {
        // Find opposite vertex to our identified vertex
        Vertex& adjacent = *edge->getOpposite(this);

        adjacent.removeEdge(edge); // Find adjacent vertex

        removeEdge(edge); // Take away edge from vertex

        delete edge; // Remove edge object
    }
}