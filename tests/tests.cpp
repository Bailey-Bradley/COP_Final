#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("Testing the testing") { // Tests if catch is functioning properly
    REQUIRE( 1 == 1);
}
// Testing if addition functions correctly
TEST_CASE("Add Vertices") {
    Graph g; // Identifying our graph
    // Choosing 2 vertices to sum together
    g.addVertex("A");
    g.addVertex("B");
    std::vector<std::string> path; // Setting up vector

    REQUIRE(g.shortestPath("A","B", path) == (unsigned long)-1);
    )
}