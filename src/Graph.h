#include <vector>
#include <list>
#include <string>

#include "Vertex.h"
#include "GraphBase.hpp"

class Graph : GraphBase {

    std::list<Vertex> vertices;

public:

    void addVertex(std::string label) override;
    void addEdge(std::string label1, std::string label2, unsigned long weight) override;

    void removeVertex(std::string label) override;
    void removeEdge(std::string label1, std::string label2) override;
    
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) override;
};