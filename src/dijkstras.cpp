#include "dijkstras.h"
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <limits> 
#include <algorithm>

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
        std::pair <int, int> current = pq.top();
        pq.pop();
        int u = current.second;
        if (visited[u]) continue;
        visited[u] = true;
        for (const auto& neighbor : G.adjacency_list[u])
        {
            int v = neighbor.vertex;
            int weight = neighbor.weight;
            if(!visited[v] && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination)
{
    vector<int>shortest_path;
    if(destination < 0 || destination >= int(distances.size()))
    {
        return shortest_path;
    }
    else if(distances[destination] == INT_MAX)
    {
        return shortest_path;
    }
    for(int i = destination; i != -1; i = previous[i])
    {
        shortest_path.push_back(i);
    }
    reverse(shortest_path.begin(), shortest_path.end());
    return shortest_path;
}

void print_path(const vector<int>& v, int total)
{
    if (v.empty())
    {
        std::cout << "\nTotal cost is " << total << "\n";
        return;
    }
    else
    {
        for (size_t i = 0; i < v.size(); ++i)
        {
            std::cout << v[i];
            if (i < v.size() - 1)
            {
                std::cout << " ";
            }
        }
    }
    std::cout << " \nTotal cost is " << total << "\n";
}