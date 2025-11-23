/*
Vertex.cpp

Implements vertex class used in graph data structure
*/

#include "Vertex.h"
#include "Edge.h"

const std::string& Vertex::getLabel() { return label; }

const PriorityQueue<Edge*, isLessPriority>& Vertex::getEdges() {
    return edges;
}

Edge* Vertex::getEdge(std::string label) {
    const std::list<Edge*> edge_list = edges.getQueue();

    for (Edge* edge : edge_list) {
        Vertex& adjacent = *edge->getOpposite(this);

        if (adjacent.label == label) {
            return edge;
        }
    }

    return nullptr;
}

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

void Vertex::addEdge(Edge* edge) {
    edges.enqueue(edge);
}

void Vertex::removeEdge(Edge* edge) {
    edges.remove(edge);
}

bool Vertex::isAdjacentTo(const Vertex& vertex) {
    const std::list<Edge*> edge_list = edges.getQueue();

    for (Edge* edge : edge_list) {
        Vertex* adjacent = edge->getOpposite(this);

        if (adjacent == &vertex) {
            return true;
        }
    }

    return false;
}

Vertex::Vertex() : label("INVALID"), edges(PriorityQueue<Edge*, isLessPriority>()) {}

Vertex::Vertex(std::string label) : label(label), edges(PriorityQueue<Edge*, isLessPriority>()) {}

Vertex::~Vertex() {
    const std::list<Edge*> edge_list = edges.getQueue();

    for (Edge* edge : edge_list) {
        Vertex& adjacent = *edge->getOpposite(this);

        adjacent.removeEdge(edge);

        removeEdge(edge);

        delete edge;
    }
}