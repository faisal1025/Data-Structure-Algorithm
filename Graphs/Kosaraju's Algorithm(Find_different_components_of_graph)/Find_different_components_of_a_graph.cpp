
// kosaraju's Algorithm on a directed graph

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        // Function to transpose the given graph like 0->1 changed to 1->0
        vector<int> * transpose(vector<int> adj[], int V){
            vector<int> *adj1 = new vector<int>[V];
            for(int i = 0; i < V; i++){
                for(auto adjNode : adj[i]){
                    adj1[adjNode].push_back(i);
                }
            }
            return adj1;
        }

        // Function to get the topological Sort order
        void topologicalSort(vector<int> adj[], vector<int> &visited, stack<int> &st, int node){
            
            visited[node] = 1;

            for(auto adjNode : adj[node]){
                if(!visited[adjNode]){
                    topologicalSort(adj, visited, st, adjNode);
                }
            }

            st.push(node);
        }

        // Function to get the no. of Compmonents from transposed graph
        void dfsComp(int node, vector<int> transAdj[], vector<int> &visited){
            visited[node] = 1;

            for(auto adjNode : transAdj[node]){
                if(!visited[adjNode])
                    dfsComp(adjNode, transAdj, visited);
            }
        }

    public:
        //Function to find number of strongly connected components in the graph.
        int kosaraju(int V, vector<int> adj[]){
            stack<int> st;
            vector<int> visited(V, 0);
            for(int i = 0; i < V; i++){
                if(!visited[i])
                topologicalSort(adj, visited, st, i);
            }
            int cnt = 0;
            vector<int> *transAdj = transpose(adj, V);
            for(int i = 0; i < V; i++){
                visited[i] = 0;
            }
            while(!st.empty()){
                int i = st.top();
                st.pop();
                if(!visited[i]){
                    cnt++;
                    dfsComp(i, transAdj, visited);
                }
            }

            return cnt;
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
    }
    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout<<ans<<endl;
    return 0;
}