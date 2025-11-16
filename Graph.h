#include <vector>
#include <string>

#include "Vertex.h"

class Graph {

    std::vector<Vertex> vertices;

public:

    const std::vector<Vertex>& getVertices();

    void addVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);

    void removeVertex(std::string label);
    void removeEdge(std::string label1, std::string label2);
    
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
};