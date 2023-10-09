#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // DFS function to traverse the graph
    void dfs(int v, int &vertices, int &edges, vector<vector<int>> &adj,
             vector<int> &visited)
    {
        visited[v] = 1;
        vertices++;             // Counting the number of vertices
        edges += adj[v].size(); // Counting the number of edges
        for (auto to : adj[v])
        {
            if (!visited[to])
            {
                dfs(to, vertices, edges, adj, visited);
            }
        }
    }

    // Function to find the number of "good" components
    int findNumberOfGoodComponent(int V, vector<vector<int>> &adj)
    {
        int ans = 0;
        vector<int> visited(V + 1, 0);

        for (int i = 1; i <= V; i++)
        {
            // Check if the vertex is visited or not
            if (!visited[i])
            {
                int vertices = 0, edges = 0;
                dfs(i, vertices, edges, adj, visited);
                // Checking if the component is "good"
                edges /= 2;
                if (edges == (vertices * (vertices - 1)) / 2)
                    ans++;
            }
        }
        return ans;
    }
};

int main()
{
    // Example usage:
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V + 1);

    // Initialize the adjacency list for your graph here
    // ...

    Solution solution;
    int numberOfGoodComponents = solution.findNumberOfGoodComponent(V, adj);

    cout << "Number of good components: " << numberOfGoodComponents << endl;

    return 0;
}
