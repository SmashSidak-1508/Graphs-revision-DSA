#include <iostream>
#include <vector>
#include <utility> // for std::pair
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        // If it's an undirected graph, you can add this line:
        // adj[v].push_back({u, weight});
    }
}
