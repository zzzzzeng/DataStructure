#include"../../Graph/Graph/Graph.h"
int main() {
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 2);
    cout << "BFS: ";
    g.BFS(0);
    cout << endl;
    cout << "DFS: ";
    g.DFS(0);
    cout << endl;
    cout << "最短路径: ";
    g.shortestPath(0);
    cout << endl;
    cout << "最小支撑树: " << endl;
    g.minSpanningTree();
    return 0;
}