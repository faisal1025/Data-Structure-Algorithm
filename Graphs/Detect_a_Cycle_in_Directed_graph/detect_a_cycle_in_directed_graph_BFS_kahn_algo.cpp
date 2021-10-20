#include<bits/stdc++.h>
using namespace std;

vector<int> * createGraph(int V, int e){

    vector<int> *adjlist = new vector<int> [V];
    
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
    }

    return adjlist;
}

class Solution
{
    private:
    
    int kahnAlgoBfs(int V, vector<int> adj[], int indegree[], queue<int> &q){
        
        int cnt = 0;
        while(!q.empty()){
            int curr_node = q.front();
            cnt++;
            q.pop();
            for(auto node : adj[curr_node]){
                indegree[node]--;
                if(indegree[node] == 0){
                    q.push(node);
                }
            }
        }
        return cnt;
    }
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	int indegree[V] = {0};
	   	for(int i = 0; i < V; i++){
	   	    for(auto j : adj[i]){
	   	        indegree[j]++;
	   	    }
	   	}
	   	queue<int> q;
	   	for(int j = 0; j < V; j++){
	   	    if(indegree[j] == 0){
	   	        q.push(j);
	   	    }
	   	}
	   	
	   	int res = kahnAlgoBfs(V, adj, indegree, q);
	   	if(res == V){
	   	    return false;
	   	}else{
	   	    return true;
	   	}
	   	
	}
};

int main(){
    int V, e;
    cin>>V>>e;
    vector<int> * adj = createGraph(V, e);
    Solution obj;
    if(obj.isCyclic(V, adj)) cout<<"1";
    else cout<<"0";
    return 0;
}