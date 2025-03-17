#include "dijkstras.h"
#include <climits>


struct Node
{
    int vertex;
    int weight;
};

struct Graph
{
    vector<vector<Node>> adjacencyList;
    vector<int> distance;
    vector<int> previous;
    vector<bool> visited;
};


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int n = G.adjacency_list.size();
    vector<int>distance(n, INT_MAX);
    previous.resize(n, -1);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    distance[source] = 0;

    while(!pq.empty())
    {
        int current = pq.top();
        pq.pop();
        int u = current.vertex;
        if (visited[u]) continue;
        visited[u] = true;
        for (auto& neighbor : G.adjacency_list[u])
        {
            int v = neighbor.vertex;
            int weight = neighbor.weight;
            if(!visited[u] && distance[v] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push(Node(v, distance[v]))
            }
        }
        return distance;
    }
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    vector<int>shortest_path;
    if(distance < 0 || distance > int(distances.size()))
    {
        return shortest_path;
    }
    else if(distance[destination] == INT_MAX)
    {
        return shortest_path;
    }
    for(int i = destination; i != -1; i = previous[i])
    {
        shortest_path.push_back[i];
    }
    reverse(shortest_path.begin(), path.end());
    return shortest_path;
}

void print_path(const vector<int>& v, int total)
{
    if(v.empty())
    {
        return;
    }
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout<< v[i];
    }
    std::cout << std::endl;
}