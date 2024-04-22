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
    void DFS(int vertex);
    void BFS(int vertex);
    void setTraversalOption(bool option) { this->printTraversal = option; }
private:
};

#endif // GRAPH_H
