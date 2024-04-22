#include <iostream>
#include <ctime>
#include <chrono>
#include "graph.h"
using namespace std;

// Function to randomly generate a graph tree with specified number of vertices and edges
// NOTE: This is a tree to prevent isolated vertices on random generation.
Graph generateRandomTree(int numVertices) {
    // N - 1 edges for a tree
    int numEdges = numVertices - 1;
    // Seed the random number generator
    srand(time(nullptr));
    // Keep track of parent vertex for each vertex (unless root)
    vector<int> parent(numVertices, -1);
    // Pick a root
    int root = rand() % numVertices;
    // Create graph to return
    Graph randomGraph(numVertices);

    // Generate edges to form a tree
    for (int vertex = 1; vertex < numVertices; vertex++) {
        //if (vertex != root) { // This condition breaks results, causing the search algos to not traverse every vertex
            int parentVertex = rand() % vertex; // Choose a random vertex as parent
            parent[vertex] = parentVertex;
            randomGraph.addEdge(parentVertex, vertex);
        //}
    }
    return randomGraph;
}

int main() {
    // A random graph
    Graph randomGraph = generateRandomTree(100000);

    // DFS
    std::cout << "DFS result of a random graph starting from 0:" << std::endl;
    auto start = chrono::high_resolution_clock::now();
    randomGraph.DFS(0);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    std::cout << "The algorithm took " << duration.count() << " microseconds for DFS." << std::endl << std::endl;

    // BFS
    std::cout << "BFS result of a random graph starting from 0:" << std::endl;
    start = chrono::high_resolution_clock::now();
    randomGraph.BFS(0);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    std::cout << "The algorithm took " << duration.count() << " microseconds for BFS." << std::endl;

    return 0;
}
