

class Edge {

    Vertex* vertex1;
    Vertex* vertex2;

    unsigned long cost;

public:

    // When passed one of the vertexes on an edge, it returns the other. Returns NULL if you supplied a vertex that it doesn't even have
    Vertex* getOpposite(const Vertex& vertex);

    // Returns whether the edge you supplied is effectively equal to this one
    // (i.e. vertex1 of supplied edge is equal to either vertex1 or vertex2 of this edge and likewise for vertex2 of the edge supplied)
    bool isEqual(const Edge& edge);
    bool isEqual(const Edge* const edge);

    bool isIncidentOn(const Vertex& vertex);
    bool isIncidentOn(const Vertex* const vertex);
};