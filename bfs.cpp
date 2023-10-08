#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    int vis[V];
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

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

    vector<int> result = bfsOfGraph(V, adj);

    cout << "BFS traversal of the graph: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
