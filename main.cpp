#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

class Graph {
    private:
        std::vector<std::list<int>> adjList;
        int task;
        int dependecy;
    public:
        Graph(int n, int m) {
            task = n; // vertices
            dependecy = m; // edges
        }

        void generateGraph();
        void printGraph();
};

void Graph::generateGraph() {
    srand(time(0));
    for (int i = 0; i < dependecy; i++) {
        int u = rand() % task;
        int v = rand() % task;
        
        adjList[u].push_back(v);
    }
    
}

void Graph::printGraph() {
    for (int i = 0; i < task; i++) {
        std::cout << i << " : ";
        for (int j : adjList[i]) {
            std::cout << j << " -> ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int N = 6;
    int M = 8;

    Graph graph(N, M);
    graph.generateGraph();
    graph.printGraph();
}