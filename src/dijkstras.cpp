#include "dijkstras.h"
#include <climits>
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int n = Graph.adjacency_list.size();
    std::vector<int>Distances(n, INT_MAX);
    previous.resize(n, -1);
    std::vector<bool> visited(n, false);
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
    vector<int>path;
    if(distance < 0 || distance > int(distances.size()))
    {
        return path;
    }
    else if(distance[destination] == INT_MAX)
    {
        return path;
    }
    for(int i = destination; i != -1; i = previous[i])
    
}

void print_path(const vector<int>& v, int total)
{
    
}