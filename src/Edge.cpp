#include "Edge.h"

bool Edge::Comparator::operator()(const Edge *const edge1, const Edge *const edge2) const {
    return edge1->weight < edge2->weight;
}

bool Edge::Comparator::operator()(const Edge &edge1, const Edge &edge2) const {
    return edge1.weight < edge2.weight;
}