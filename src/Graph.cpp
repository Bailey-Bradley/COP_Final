// Christian McMillen
#include <stdexcept>

#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

class PriorityQueue {}; // THIS IS JUST TO MAKE INTELLISENSE SHUT UP WHILE WE DONT HAVE A PRIORTIY QUEUE

void Graph::addVertex(std::string label) {
    vertices.try_emplace(label, Vertex(label));
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    try {

        vertices.at(label1);
        vertices.at(label2);

    }
    catch (const std::out_of_range& e) {
        return;
    }

    Vertex& vertex1 = vertices[label1];
    Vertex& vertex2 = vertices[label2];

    if (vertex1.isAdjacentTo(vertex2)) return;

    Edge* newEdge = new Edge(&vertex1, &vertex2, weight);

    vertex1.addEdge(newEdge);
    vertex2.addEdge(newEdge);
}

void Graph::removeVertex(std::string label) {
    vertices.erase(label);
}

void Graph::removeEdge(std::string label1, std::string label2) {
    try {
        vertices.at(label1);
        vertices.at(label2);
    } catch (const std::out_of_range& e) {
        return;
    }

    Vertex& vertex1 = vertices[label1];
    Vertex& vertex2 = vertices[label2];

    if (vertex1.isAdjacentTo(vertex2)) {
        Edge* edge = vertex1.getEdge(vertex2);

        vertex1.removeEdge(edge);
        vertex2.removeEdge(edge);
    }
}

unsigned long Graph::shortestPath(std::string startLabel, std::vector<std::string> &path) {
    PriorityQueue pq;


}