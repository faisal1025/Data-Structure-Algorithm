#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfsGraph(vector<int> adj[],int node,vector<int>&visited, queue<int> &q){
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto j : adj[curr]){
                if(!visited[j]){
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int ans = -1;
        vector<int> visited(n, 0);
        vector<int> adj[n];
        int edges = connections.size();
        if (n - 1 > edges)
        {
            return ans;
        }
        else
        {
            for (auto wire : connections)
            {
                adj[wire[0]].push_back(wire[1]);
                adj[wire[1]].push_back(wire[0]);
            }
            queue<int> q;
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    ans++;
                    q.push(i);
                    visited[i] = 1;
                    bfsGraph(adj, i, visited, q);
                }
            }
        }
        
        return ans;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> connection(1000, vector<int>(2, 0));
    for (int i = 0; i < e; i++)
    {
        for(int j = 0; j < 2; j++){
            cin>>connection[i][j];
        }

    }
    /*
            10 13
            0 4 1 6 2 9 4 7 0 6 6 9 4 8 1 4 4 9 1 8 2 8 3 4 0 9

            ans : 1
    */
    Solution obj;
    int result = obj.makeConnected(n, connection);
    cout << result;
    return 0;
}