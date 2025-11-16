

class Edge {

    Vertex& vertex1;
    Vertex& vertex2;

    unsigned long cost;

public:

    Vertex& getOpposite(const Vertex& vertex);
    unsigned long getCost();

};