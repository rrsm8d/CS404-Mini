#include "graph.h"
#include <stack>
#include <queue>

// Initialize graph
Graph::Graph(int vertices) {
    this->vertexCount = vertices;
    this->adjLists.resize(vertices);
}

// Add edges for nodes
void Graph::addEdge(int src, int dest) {
    this->adjLists[src].push_back(dest);
    this->adjLists[dest].push_back(src); // For undirected graph
}

// DFS algorithm
void Graph::DFS(int startingVertex) {

    std::stack<int> stack;
    std::vector<bool> visitedVertices(this->vertexCount, false);
    stack.push(startingVertex);
    int currentVertex;

    while(!stack.empty()) {

        currentVertex = stack.top();
        stack.pop();

        // If vertex not visited yet, add to traversal list
        if (!visitedVertices[currentVertex]) {

             visitedVertices[currentVertex] = true;
            // Optional print path taken
            if(this->printTraversal)
                std::cout << currentVertex << " ";

            // Add the adjacent vertices to stack
            for (int neighbor : adjLists[currentVertex])
                stack.push(neighbor);
        }
    }
    //std::cout << std::endl;
}

// Breadth First Search traversal from a given source vertex
void Graph::BFS(int startingVertex) {

    std::queue<int> queue;
    std::vector<bool> visitedVertices(this->vertexCount, false);
    queue.push(startingVertex);
    int currentVertex;

    while (!queue.empty()) {

        currentVertex = queue.front();
        queue.pop();

        // If vertex not visited yet, add to traversal list
        if (!visitedVertices[currentVertex]) {

            visitedVertices[currentVertex] = true;
            // Optional print path taken
            if(this->printTraversal)
                std::cout << currentVertex << " ";

            // Add the adjacent vertices to queue
            for (int neighbor : adjLists[currentVertex])
                queue.push(neighbor);
        }
    }
    //std::cout << std::endl;
}
