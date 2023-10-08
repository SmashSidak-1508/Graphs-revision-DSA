#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Graph
{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, ls);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // int vis[V] = {0};
        int vis[V];
        memset(vis, 0, sizeof(vis));
        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};

int main()
{
    // Example usage
    int V = 5; // Number of vertices
    vector<int> adj[V];

    // Add edges to the adjacency list
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    Graph g;
    vector<int> result = g.dfsOfGraph(V, adj);

    cout << "DFS traversal of the graph: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
