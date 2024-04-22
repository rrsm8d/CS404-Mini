#include "graph.h"
#include <stack>
#include <queue>

// Initialize graph
Graph::Graph(int vertices) {
    this->vertexCount = vertices;
    this->adjLists.resize(vertices);
}

// Add edges
void Graph::addEdge(int src, int dest) {
    this->adjLists[src].push_back(dest);
}

// DFS algorithm
void Graph::DFS(int startingVertex) {
    std::vector<bool> visitedVertices(this->vertexCount, false);

    std::stack<int> stack;
    stack.push(startingVertex);

    while(!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();

        // If vertex not visited yet
        if (!visitedVertices[currentVertex]) {
            if(this->printTraversal) // Optionally print traversal path
                std::cout << currentVertex << " ";
            visitedVertices[currentVertex] = true;
        }

        // Visit adjacent vertices and push onto stack for searching
        for (int neighbor : adjLists[currentVertex]) {
            stack.push(neighbor);
        }
    }
    std::cout << std::endl;
}

// Breadth First Search traversal from a given source vertex
void Graph::BFS(int start) {
    // Vector to keep track of visited vertices
    std::vector<bool> visitedVertices(this->vertexCount, false);

    std::queue<int> queue;
    // Enqueue the start vertex
    queue.push(start);
    visitedVertices[start] = true;

    while (!queue.empty()) {
        // Dequeue a vertex from queue
        int currentVertex = queue.front();
        queue.pop();
        if(this->printTraversal)
            std::cout << currentVertex << " ";

        // Visit all adjacent vertices of dequeued vertex
        for (int neighbor : adjLists[currentVertex]) {
            if (!visitedVertices[neighbor]) {
                visitedVertices[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}
