#include "Edge.h"
#include "Vertex.h"

Edge::Edge(Vertex* v1, Vertex* v2, unsigned long weight) : vertex1(v1), vertex2(v2), weight(weight) {}

Vertex* Edge::getOpposite(const Vertex* const vertex) {
    if (vertex == vertex1) {
        return vertex2;
    } else if (vertex == vertex2) {
        return vertex1;
    } else {
        return nullptr;
    }
}

bool Edge::isEqual(const Edge &edge) {
    if (edge.vertex1 == vertex1 && edge.vertex2 == vertex2 && edge.weight == weight) {
        return true;
    } else if (edge.vertex1 == vertex2 && edge.vertex2 == vertex1 && edge.weight == weight) {
        return true;
    } else {
        return false;
    }
}

bool Edge::isEqual(const Edge *const edge) {
    return isEqual(*edge);
}

bool Edge::isIncidentOn(const Vertex &vertex) {
    if (&vertex == vertex1 || &vertex == vertex2) {
        return true;
    }

    return false;
}

bool Edge::isIncidentOn(const Vertex *const vertex) {
    return isIncidentOn(*vertex);
}

bool isLessPriority(const Edge* edge1, const Edge* edge2) {
    return edge1->weight < edge2->weight;
}