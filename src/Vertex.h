#include <string>
#include <memory>

#include "Edge.h"
#include "PriorityQueue.h"

class Vertex {

    std::string label;
    // TODO:
    // Make our own priority queue and use it to store the edges:
    PriorityQueue<Edge*, Edge::Comparator> edges;

public:

    Vertex(std::string);

    const std::string& getLabel();
    const PriorityQueue<Edge*, Edge::Comparator>& getEdges();

    // Returns the edge between this vertex and the one with the given label if that edge exists
    // Returns NULL if it doesn't exist
    Edge* getEdge(std::string label);
    Edge* getEdge(const Vertex& vertex);

    // Pretty much unintelligently just adds the edge pointer to the PQ
    void addEdge(Edge*);

    // Again, unintelligently removes the edge given if it even has it
    void removeEdge(Edge*);

    bool isAdjacentTo(const Vertex& vertex);

    // Iterates over every edge this vertex has.
    // for every edge, it gets the other vertex on the other end of the edge and calls removeEdge(edge) on it to
    // make sure that none of the vertices adjacent to this one refer to it any more
    // It then deletes every edge object it has.
    ~Vertex();
};