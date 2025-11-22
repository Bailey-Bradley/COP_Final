// Christian McMillen
#include <stdexcept>

#include "Edge.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include "Vertex.h"

void Graph::addVertex(std::string label) {
    vertices.try_emplace(label, Vertex(label));
}

void Graph::addEdge(std::string label1, std::string label2,
                    unsigned long weight) {
    try {

        vertices.at(label1);
        vertices.at(label2);

    } catch (const std::out_of_range &e) {
        return;
    }

    Vertex &vertex1 = vertices[label1];
    Vertex &vertex2 = vertices[label2];

    if (vertex1.isAdjacentTo(vertex2))
        return;

    Edge *newEdge = new Edge(&vertex1, &vertex2, weight);

    vertex1.addEdge(newEdge);
    vertex2.addEdge(newEdge);
}

void Graph::removeVertex(std::string label) { vertices.erase(label); }

void Graph::removeEdge(std::string label1, std::string label2) {
    try {
        vertices.at(label1);
        vertices.at(label2);
    } catch (const std::out_of_range &e) {
        return;
    }

    Vertex &vertex1 = vertices[label1];
    Vertex &vertex2 = vertices[label2];

    if (vertex1.isAdjacentTo(vertex2)) {
        Edge *edge = vertex1.getEdge(vertex2);

        vertex1.removeEdge(edge);
        vertex2.removeEdge(edge);
    }
}

bool compareVertices(std::pair<Vertex *, int> v1, std::pair<Vertex *, int> v2) {
    return v1.second < v2.second;
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    std::vector<Vertex*> processed;

    PriorityQueue<std::pair<Vertex*, int>, compareVertices> vertexQueue;

    try {
        vertices.at(startLabel);
    } catch (const std::out_of_range &e) {
        return -1;
    }

    Vertex &startVertex = vertices[startLabel];

    return -1;
}