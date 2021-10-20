#include<bits/stdc++.h>
using namespace std;

vector<int>  * createGraph(int V, int e){
    vector<int> *adjlist = new vector<int>[V];

    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    return adjlist;
}

bool isCyclicBfs(int curr_node, vector<int>adj[], vector<bool>&visited, queue<pair<int, int>> &q){
        while(!q.empty()){
	        pair<int, int> curr_node = q.front();
            int curr = curr_node.first;
            int parent = curr_node.second;
	        q.pop();
	        for(auto node : adj[curr]){
                if(node!=parent){
                    if(visited[node] == false){
                        q.push({node, curr});
                        visited[node] = true;
                    }else{
                        return true; 
                    }
                }
	        }
	    }
	    return false;
}

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool> visited(V, false);
	    queue<pair<int, int>> q;
	    for(int i = 0; i < V; i++){
            if(!visited[i]){
                q.push({i, -1});
                visited[i] = true;
                if(isCyclicBfs(i, adj, visited, q)) return true;
            }
	    }
	    return false;
	}
};

int main(){
    int v, e;
    cin>>v>>e;
    vector<int> *adj = createGraph(v, e);
    Solution obj;
    cout<<obj.isCycle(v,  adj);
}