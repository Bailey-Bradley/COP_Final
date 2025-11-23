#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Graph.h"
TEST_CASE("Testing the testing") { // Tests if catch is functioning properly
    REQUIRE( 1 == 1);
}

TEST_CASE("Final Project Test Cases for Dijkstra's Algorithm") {
    Graph g;

    SECTION("Should return infinity for non-connected vertices") {
        g.addVertex("A");
        g.addVertex("B");
        std::vector<std::string> path;

        REQUIRE(g.shortestPath("A","B", path) == (unsigned long)-1);
    }

    SECTION("Should return shortest path without getting stuck in a cycle") {
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addEdge("A","B",1);
        g.addEdge("B","C",1);
        g.addEdge("C","A",1);
        std::vector<std::string> path;

        REQUIRE(g.shortestPath("A","C", path) == 2);
    }
}