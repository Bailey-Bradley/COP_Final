

class Edge {

    Vertex* vertex1;
    Vertex* vertex2;

    unsigned long cost;

public:

    Vertex& getOpposite(const Vertex& vertex);

    bool isEqual(const Edge& edge);
    bool isEqual(const Edge* const edge);

    bool isIncidentOn(const Vertex& vertex);
    bool isIncidentOn(const Vertex* const vertex);
};