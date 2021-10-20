
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int level;
    Node(int val, int lev){
        data = val;
        level = lev;
    }
};


class Solution {
    private:
        bool bfsColoring(int data, vector<int> adj[], int V, vector<int> &visited){
            queue<Node> q;
            Node node = Node(data, 0);
            q.push(node);
            while(!q.empty()){
                Node cur = q.front();
                int val = cur.data;
                int lev = cur.level;
                q.pop();
                if(visited[val] != -1){
                    if(visited[val] != lev){
                        return false;
                    }
                }
                else{
                    visited[val] = lev;
                }
                for(auto adjNode : adj[val]){
                    if(visited[adjNode] == -1){
                        node = Node(adjNode, lev+1); 
                        q.push(node);
                    }
                }
            }
            return true;
        }

    public:
        bool isBipartite(int V, vector<int> adj[]){
            vector<int> visited(V, -1);
            for(int i = 0; i < V; i++){
                if(visited[i] == -1){
                    bool is_bipartite = bfsColoring(i, adj, V, visited);
                    if(is_bipartite == false){
                        return false;
                    }
                }
            }

            return true;
        }
};

int main(){
    int n, e;
    cin>>n>>e;
    vector<int> adj[n];
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Solution obj;
    cout<<obj.isBipartite(n, adj);
}