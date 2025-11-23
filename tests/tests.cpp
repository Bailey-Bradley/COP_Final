#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Graph.h"

TEST_CASE("Final Project Test Cases for Dijkstra's Algorithm") {
    Graph g;

    SECTION("Should return the shortest path") {
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addVertex("D");
        g.addVertex("E");
        g.addEdge("A","B",4);
        g.addEdge("A","C",2);
        g.addEdge("B","C",5);
        g.addEdge("B","D",10);
        g.addEdge("C","E",3);
        g.addEdge("E","D",4);
        std::vector<std::string> path;

        REQUIRE(g.shortestPath("A","D", path) == 9);
    }

    SECTION("Should return infinity for non-connected vertices") {
        g.addVertex("A");
        g.addVertex("B");
        std::vector<std::string> path;

        REQUIRE(g.shortestPath("A","B", path) == (unsigned long)-1);
    }

    SECTION("Should return infinity if start vertex does not exist") {
        g.addVertex("A");
        std::vector<std::string> path;
        
        REQUIRE(g.shortestPath("X","A", path) == (unsigned long)-1);
    }

    SECTION("Should return shortest path without getting stuck in a cycle") {
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addEdge("A","B",1);
        g.addEdge("B","C",1);
        g.addEdge("C","A",1);
        std::vector<std::string> path;

        REQUIRE(g.shortestPath("A","C", path) == 1);
    }

    SECTION("Should return 0 when the edges have zero weight") {
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addVertex("D");
        g.addEdge("A","B",0);
        g.addEdge("B","C",0);
        g.addEdge("C","A",0);
        g.addEdge("C","D",0);
        std::vector<std::string> path;

        REQUIRE(g.shortestPath("A","C", path) == 0);
    }

    SECTION("Vertex should return 0 when pathing to itself") {
        g.addVertex("A");
        std::vector<std::string> path;

        REQUIRE(g.shortestPath("A","A", path) == 0);
    }

    SECTION("Should return lowest edge weight when two vertexes have multiple edges") {
        g.addVertex("A");
        g.addVertex("B");
        g.addEdge("A","B",3);
        g.addEdge("A","B",2);
        g.addEdge("A","B",1);
        std::vector<std::string> path;

        REQUIRE(g.shortestPath("A","B", path) == 1);
    }

    SECTION("Shortest path should fill the path vector correctly") {
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addVertex("D");
        g.addEdge("A","B",1);
        g.addEdge("B","C",1);
        g.addEdge("C","D",1);
        std::vector<std::string> path;

        g.shortestPath("A","D", path);

        REQUIRE(path == std::vector<std::string>{"B","C","D"});
    }

    SECTION("Output should update when an edge is removed") {
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addEdge("A","B",12);
        g.addEdge("B","C",1);
        g.addEdge("C","A",1);
        std::vector<std::string> path;

        REQUIRE(g.shortestPath("A","B", path) == 2);

        g.removeEdge("A", "C");

        REQUIRE_FALSE(g.shortestPath("A","B", path) == 2);
    }
}