#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Function to implement Dijkstra's algorithm for network routing
void dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    distance[source] = 0;


    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();


        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;


            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }


    // Output the result in a user-friendly format
    cout << "Shortest distances from node " << source << " to all other nodes:\n";
    for (int i = 0; i < n; ++i) {
        if (distance[i] == INF)
            cout << "Node " << i << ": Not reachable\n";
        else
            cout << "Node " << i << ": " << distance[i] << " units away\n";
    }
}


int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;


    vector<vector<pair<int, int>>> graph(nodes);


    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Assuming the graph is undirected
    }


    int source;
    cout << "Enter the source node: ";
    cin >> source;


    dijkstra(graph, source);


    return 0;
}
