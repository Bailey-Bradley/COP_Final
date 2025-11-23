/*
GraphBase.hpp:

This file is an abstract base class that defines the outline of the graph
*/
#pragma once

#include <vector>
#include <string>

class GraphBase {
    // Add vertex to the graph
    virtual void addVertex(std::string label) = 0;

    // Remove vertex and connected edges from graph
    virtual void removeVertex(std::string label) = 0;

    // Adds an edge with edge weight between vertices 
    virtual void addEdge(std::string label1, std::string label2, unsigned long weight) = 0;

    // Removes edge between adjacent vertices
    virtual void removeEdge(std::string label1, std::string label2) = 0;
    
    // Calculates least cost path from startLabel to endLabel using Dijkstra's Algorithm
    // Returns total cost
    virtual unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) = 0;
};