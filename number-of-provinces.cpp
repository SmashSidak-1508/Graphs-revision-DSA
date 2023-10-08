#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj_list[], int vis[])
    {
        vis[node] = 1;
        for (auto it : adj_list[node])
        {
            if (!vis[it])
            {
                dfs(it, adj_list, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> &adj, int V)
    {
        // int vis[V] = {0};
        int vis[V];
        memset(vis, 0, sizeof(vis));
        vector<int> adj_list[V];

        // Construct the adjacency list from the adjacency matrix
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }

        int count = 0; // Count the number of provinces

        // Perform DFS to find connected components (provinces)
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, adj_list, vis);
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;

    // Example usage
    int V = 3; // Number of cities (vertices)
    vector<vector<int>> adjacencyMatrix = {{1, 1, 0},
                                           {1, 1, 0},
                                           {0, 0, 1}};

    int provinces = solution.numProvinces(adjacencyMatrix, V);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
