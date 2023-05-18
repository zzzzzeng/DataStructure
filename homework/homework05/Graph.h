#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 邻接表节点结构体
struct AdjListNode {
    int dest;
    int weight;
    AdjListNode* next;
};

// 邻接表头结构体
struct AdjList {
    AdjListNode* head;
};

// 图结构体
class Graph {
private:
    int V; // 顶点数
    vector<AdjList> adj; // 邻接表数组

public:
    Graph(int V); // 构造函数
    void addEdge(int src, int dest, int weight); // 添加边
    void BFS(int start); // 广度优先搜索算法
    void DFS(int start); // 深度优先搜索算法
    void shortestPath(int start); // 最短路径算法
    void minSpanningTree(); // 最小支撑树算法
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
    for (int i = 0; i < V; i++) {
        adj[i].head = NULL;
    }
}

void Graph::addEdge(int src, int dest, int weight) {
    AdjListNode* newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = adj[src].head;
    adj[src].head = newNode;
}

void Graph::BFS(int start) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        AdjListNode* node = adj[u].head;
        while (node != NULL) {
            int v = node->dest;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
            node = node->next;
        }
    }
    delete[] visited;
}

void Graph::DFS(int start) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    stack<int> s;
    visited[start] = true;
    s.push(start);
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        cout << u << " ";
        AdjListNode* node = adj[u].head;
        while (node != NULL) {
            int v = node->dest;
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
            node = node->next;
        }
    }
    delete[] visited;
}

void Graph::shortestPath(int start) {
    int* dist = new int[V];
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[start] = 0;
    for (int i = 0; i < V - 1; i++) {
        int u = -1;
        for (int j = 0; j < V; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = true;
        AdjListNode* node = adj[u].head;
        while (node != NULL) {
            int v = node->dest;
            int weight = node->weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            node = node->next;
        }
    }
    for (int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }
    delete[] dist;
    delete[] visited;
}

void Graph::minSpanningTree() {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mst(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    key[0] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        AdjListNode* node = adj[u].head;
        while (node != NULL) {
            int v = node->dest;
            int weight = node->weight;
            if (!mst[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
            node = node->next;
        }
    }
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " " << key[i] << endl;
    }
}