#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        bool bfsColoring(int node, vector<int> adj[], int V, vector<int> &color){
            color[node] = 0;
            queue<int> q;
            q.push(node);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto a : adj[cur]){
                    if(color[a] == -1){
                        if(color[cur] == 0){
                            color[a] = 1;
                        }else{
                            color[a] = 0;
                        }
                        q.push(a);
                    }else{
                        if(color[cur] == color[a]){
                            return false;
                        }
                    }
                }
            }
            return true;
        }

    public:
        bool isBipartite(int V, vector<int> adj[]){
            vector<int> color(V, -1);
            for(int i = 0; i < V; i++){
                if(color[i] == -1){
                    bool is_bipartite = bfsColoring(i, adj, V, color);
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
    return 0;
}