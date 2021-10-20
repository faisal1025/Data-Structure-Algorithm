/*
    Given a Directed Acyclic Graph having V vertices and E edges, where each 
    edge {U, V} represents the Jobs U and V such that Job V can only be started 
    only after completion of Job U. The task is to determine the minimum time 
    taken by each job to be completed where each Job takes unit time to get 
    completed.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> minTimeJob(vector<int> adj[], int n, queue<int> q, int indegree[]){
    vector<int> ans(n+1);
    int lev = 0;
    while(!q.empty()){
        lev++;
        int s = q.size();
        for(int j = 0; j < s; j++){
            int curr = q.front();
            ans[curr] = lev;
            cout<<curr<<" "<<lev<<"\n";
            q.pop();
            for(auto adjNode : adj[curr]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
    }
    return ans;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<int> adj[n+1];
    int indegree[n+1] = {0};
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    cout<<"indegree :";
    for(int i = 1; i < n+1; i++){
        cout<<indegree[i]<<" ";
    }
    queue<int> q;
    for(int i = 1; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> result = minTimeJob(adj, n, q, indegree);
    for(int i = 1; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
}