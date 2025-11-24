/*
Graph.h:

This class takes in GraphBase and handles vertices that are identified and stored

Adds & removes vertices/edges and calculates shortest path

*/
#pragma once

#include <vector>
#include <map>
#include <string>

#include "Vertex.h"
#include "GraphBase.hpp"

class Graph : public GraphBase {

    std::map<std::string, Vertex> vertices;

public:

    // Just make a new vertex and adds it to the map
    void addVertex(std::string label) override;

    // Grabs a reference to both vertices with the given labels, gets the supplied weight, and constructs an edge object from that
    // Ensures the edges aren't already connected.
    // If they aren't yet connected, give a pointer to the edge object to both via addEdge()
    // (could use isAdjacentTo() on the vertices to determine if they're connected? or just iterate over every edge in one vertex
    // and see if one of the vertex1's or vertex2's of either refers to the other vertex
    void addEdge(std::string label1, std::string label2, unsigned long weight) override;

    // Vertices automatically disconnect to other vertices via their destructor so literally just remove the vertex from the map here
    void removeVertex(std::string label) override;

    // Check if both vertices are actually adjacent via isAdjacentTo()
    // If they are, get the corresponding edge via getEdge() on one of the vertices and call removeEdge() on both vertices
    void removeEdge(std::string label1, std::string label2) override;
    
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) override;
};