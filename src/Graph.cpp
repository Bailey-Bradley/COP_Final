/*
Graph.cpp:

This implementation represents the Graph class

Adds/removes vertices and edges, finds shortest path, applies Dijkstra's Algorithm, and returns the total cost of the chosen path
*/
#include <stdexcept>

#include "Edge.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include "Vertex.h"

// Adds a new vertex to the graph.
void Graph::addVertex(std::string label) {
    vertices.try_emplace(label, Vertex(label)); // try_emplace avoids duplicate vertices
}

// Adds an edge between two vertices identified by the labels
void Graph::addEdge(std::string label1, std::string label2,
                    unsigned long weight) {
    try {
        // Checks if vertices exist
        vertices.at(label1);
        vertices.at(label2);

    // Returns if either vertex does not exist or the edge already exists
    } catch (const std::out_of_range &e) {
        return;
    }
    Vertex &vertex1 = vertices[label1];
    Vertex &vertex2 = vertices[label2];

    // Searches to see if the edge already exists
    Edge *existing = vertex1.getEdge(vertex2);

    // Updates the existing edge if the new one is a smaller weight
    if (existing) {
        if (weight < existing->weight) {
            existing->weight = weight;
        }
        return;
    }

    // Creates new edge to add to vertices
    Edge *newEdge = new Edge(&vertex1, &vertex2, weight);

    vertex1.addEdge(newEdge);
    vertex2.addEdge(newEdge);
}

// Removes the identified vertex and connected edges from the graph
void Graph::removeVertex(std::string label) { vertices.erase(label); }

// Removes edge between identifed vertices
void Graph::removeEdge(std::string label1, std::string label2) {
    try {
        vertices.at(label1);
        vertices.at(label2);
    // If the vertex or the edge does not exist just return
    } catch (const std::out_of_range &e) {
        return;
    }

    Vertex &vertex1 = vertices[label1];
    Vertex &vertex2 = vertices[label2];

    // Obtain edge and remove it from vertices
    if (vertex1.isAdjacentTo(vertex2)) {
        Edge *edge = vertex1.getEdge(vertex2);

        vertex1.removeEdge(edge);
        vertex2.removeEdge(edge);
    }
}
// This struct tracks vertices and their paths through travel calculation
struct VertexPathNode {
    Vertex *previous_vertex; // Pointer to path vertex
    Vertex *vertex; // Current
    unsigned long cost; // Cost so far

    bool operator==(const VertexPathNode& vpn) const {
        return (vpn.previous_vertex == previous_vertex) && (vpn.vertex == vertex) && (vpn.cost == cost);
    }
};

// Comparator for ordering VertexPathNodes by cost
bool compareVertices(VertexPathNode v1, VertexPathNode v2) {
    return v1.cost < v2.cost;
}

void vertexPathToStrings(std::vector<std::string>& string_array, std::vector<VertexPathNode>& vertex_paths, const std::string& end_vertex_label) {

    VertexPathNode* node = nullptr;

    for (VertexPathNode& path_node : vertex_paths) {
        if (path_node.vertex->getLabel() == end_vertex_label) {
            node = &path_node;
            break; // Break when finding the end node
        }
    }

    while (node != nullptr) {
    string_array.push_back(node->vertex->getLabel());

    if (node->previous_vertex == nullptr) // Stopping condition
        break;

    // find the previous node
    for (VertexPathNode& path_node : vertex_paths) {
        if (path_node.vertex == node->previous_vertex) {
            node = &path_node;
            break;
        }
    }
}


    std::reverse(string_array.begin(), string_array.end());
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    
    path.clear(); // If caller reuses the same vector we clear it 

    std::vector<VertexPathNode> processed;

    PriorityQueue<VertexPathNode, compareVertices> vertexQueue;

    // Ensure that there are start and end vertices
    try {
        vertices.at(startLabel);
        vertices.at(endLabel);
    } catch (const std::out_of_range &e) {
        return (unsigned long)-1; // Return when at least one vertex not found
    }

    Vertex *startVertex = &vertices[startLabel];
    vertexQueue.enqueue(VertexPathNode({nullptr, startVertex, 0}));

    Vertex *endVertex = &vertices[endLabel];

    // Loop through vertices in cost order
    while (vertexQueue.size() > 0) {
        const VertexPathNode& vertex_path_node = vertexQueue.min();

        Vertex *current_vertex = vertex_path_node.vertex;
        unsigned long current_vertex_cost = vertex_path_node.cost;

        // Navigate through every edge adjacent to the current vertex
        for (Edge *edge : current_vertex->getEdges().getQueue()) {
            Vertex *adjacent = edge->getOpposite(current_vertex);

            // Identify if adjacent vertex has already been visited
            bool shouldSkip = false;
            for (VertexPathNode& processed_pair : processed) {
                if (processed_pair.vertex == adjacent) {
                    shouldSkip = true; // If it has then skip to avoid repeats
                    break;
                }
            }

            if (shouldSkip)
                continue;
            // Take priority queue and add the adjacent vertex with the new cost
            vertexQueue.enqueue(VertexPathNode({current_vertex, adjacent, current_vertex_cost + edge->weight}));
        }

        // Identify current vertex
        processed.push_back(vertex_path_node);
        vertexQueue.dequeue();

        // Upon reaching ending vertex reconstruct the desired path
        if (current_vertex == endVertex) {
            vertexPathToStrings(path, processed, endLabel);
            return current_vertex_cost; // Return total cost
        }
    }

    // Return in case of no path being found
    return (unsigned long)-1;
}