/*
Edge.cpp:

Performs Dijstra's shortest path

This file constructs an edge that connected vertices, determines incidence, and compares edge weights
*/
#include "Edge.h"
#include "Vertex.h"

// Set up constructor
Edge::Edge(Vertex* v1, Vertex* v2, unsigned long weight) : vertex1(v1), vertex2(v2), weight(weight) {}

// Given one vertex on this edge, return the opposite vertex
Vertex* Edge::getOpposite(const Vertex* const vertex) {
    // If the input vertex is not part of this edge, return nullptr
    if (vertex == vertex1) {
        return vertex2;
    } else if (vertex == vertex2) {
        return vertex1;
    } else {
        // vertex not part included in edge
        return nullptr;
    }
}

bool Edge::isEqual(const Edge &edge) { // Check if this edge is directed
    if (edge.vertex1 == vertex1 && edge.vertex2 == vertex2 && edge.weight == weight) {
        return true;
    } else if (edge.vertex1 == vertex2 && edge.vertex2 == vertex1 && edge.weight == weight) {
        return true;
    } else {
        return false;
    }
}

// Check pointer to edge
bool Edge::isEqual(const Edge *const edge) {
    return isEqual(*edge);
}

// Check if edge is incident on vertex
bool Edge::isIncidentOn(const Vertex &vertex) {
    if (&vertex == vertex1 || &vertex == vertex2) {
        return true; // Returns true if the vertex is an endpoint
    }

    return false;
}

// Check if edge is incident on the given vertex pointer
bool Edge::isIncidentOn(const Vertex *const vertex) {
    return isIncidentOn(*vertex);
}

// Comparator that determines which edge to go to based on numerical priority
bool isLessPriority(const Edge* edge1, const Edge* edge2) {
    return edge1->weight < edge2->weight;
}