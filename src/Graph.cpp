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
struct VertexPathNode {
    Vertex *previous_vertex;
    Vertex *vertex;
    unsigned long cost;
};

bool compareVertices(VertexPathNode v1, VertexPathNode v2) {
    return v1.cost < v2.cost;
}

void vertexPathToStrings(std::vector<std::string>& string_array, std::vector<VertexPathNode>& vertex_paths, const std::string& end_vertex_label) {

    VertexPathNode* node = nullptr;

    for (VertexPathNode& path_node : vertex_paths) {
        if (path_node.vertex->getLabel() == end_vertex_label) {
            node = &path_node; 
        }
    }

    while (node->previous_vertex != nullptr) {
        string_array.push_back(node->vertex->getLabel());

        for (VertexPathNode& path_node : vertex_paths) {
            if (path_node.vertex == node->previous_vertex) {
                node = &path_node; 
            }
        }
    }

    std::reverse(string_array.begin(), string_array.end());
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {

    std::vector<VertexPathNode> processed;

    PriorityQueue<VertexPathNode, compareVertices> vertexQueue;

    try {
        vertices.at(startLabel);
        vertices.at(endLabel);
    } catch (const std::out_of_range &e) {
        return -1;
    }

    Vertex *startVertex = &vertices[startLabel];
    vertexQueue.enqueue(VertexPathNode({nullptr, startVertex, 0}));

    Vertex *endVertex = &vertices[endLabel];

    while (vertexQueue.size() > 0) {
        VertexPathNode& vertex_path_node = vertexQueue.min();

        Vertex *current_vertex = vertex_path_node.vertex;
        unsigned long current_vertex_cost = vertex_path_node.cost;

        for (Edge *edge : current_vertex->getEdges().getQueue()) {
            Vertex *adjacent = edge->getOpposite(current_vertex);

            bool shouldSkip = false;
            for (VertexPathNode& processed_pair : processed) {
                if (processed_pair.vertex == adjacent) {
                    shouldSkip = true;
                    break;
                }
            }

            if (shouldSkip)
                continue;

            vertexQueue.enqueue(VertexPathNode({current_vertex, adjacent, current_vertex_cost + edge->weight}));
        }

        processed.push_back(vertex_path_node);
        vertexQueue.dequeue();

        if (current_vertex == endVertex) {
            vertexPathToStrings(path, processed, endLabel);
            return current_vertex_cost;
        }
    }

    return -1;
}