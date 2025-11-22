#include "Edge.h"
#include "Vertex.h"

bool Edge::Comparator::operator()(const Edge *const edge1, const Edge *const edge2) const {
    return edge1->weight < edge2->weight;
}

bool Edge::Comparator::operator()(const Edge &edge1, const Edge &edge2) const {
    return edge1.weight < edge2.weight;
}

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

}

bool Edge::isIncidentOn(const Vertex *const vertex) {

}