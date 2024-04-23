#include <iostream>
#include <ctime>
#include <chrono>
#include "graph.h"
using namespace std;

// Pre: A number of vertices
// Post: Creates a randomly generated graph, connecting to other vertices randomly.
Graph generateRandomGraph(int numVertices) {

    // Seed the random number generator
    srand(time(nullptr));
    // Create graph to return
    Graph randomGraph(numVertices);

    // Generate edges
    for (int vertex = 1; vertex < numVertices; vertex++) {
        int parentVertex = rand() % numVertices; // Choose a random vertex as parent
        randomGraph.addEdge(parentVertex, vertex);
    }
    return randomGraph;
}

void testRuntime(Graph testGraph, int runCount) {

    int vertexCount = testGraph.getVertexCount();
    int durationSum = 0;
    int durationAverage = 0;
    //testGraph.setTraversalOption(true);

    // Testing for DFS
    for(int i = 0; i < runCount; i++) {
        int randomSourceVertex = rand() % vertexCount;
        auto start = chrono::high_resolution_clock::now();
        testGraph.DFS(randomSourceVertex);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
        durationSum += duration.count();
    }
    durationAverage = durationSum/runCount;

    std::cout << "DFS completed " << runCount << " times for " << vertexCount << " items. Runtime average: " << durationAverage << std::endl;
    durationSum = 0;

    // Testing for BFS
    for(int i = 0; i < runCount; i++) {
        int randomSourceVertex = rand() % vertexCount;
        auto start = chrono::high_resolution_clock::now();
        testGraph.BFS(randomSourceVertex);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
        durationSum += duration.count();
    }
    durationAverage = durationSum/runCount;

    std::cout << "BFS completed " << runCount << " times for " << vertexCount << " items. Runtime average: " << durationAverage << std::endl;

}

int main() {
    // A random graph
    Graph randomGraph = generateRandomGraph(10000);
/*
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
*/
    testRuntime(randomGraph, 1000);

    return 0;
}
