#include <string>

#include "Edge.h"

class Vertex {

    std::string label;
    // TODO:
    // Make our own priority queue and use it to store the edges:
    OUR_PQ<Edge*> edges;

public:

    const std::string& getLabel();
    const OUR_PQ<Edge>& getEdges();

};