#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

class Graph
{
private:
    int vertexCount;
    bool printTraversal = false;
    std::vector<std::vector<int>> adjLists;
public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void DFS(int startingVertex);
    void BFS(int startingVertex);
    void setTraversalOption(bool option) { this->printTraversal = option; }
    int getVertexCount() { return this->vertexCount; }
private:
};

#endif // GRAPH_H
