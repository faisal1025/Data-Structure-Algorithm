#include<bits/stdc++.h>
using namespace std;

bool isPossibleToComplete(vector<int> adj[], int n, queue<int> q, int indegree[]){
    int cnt = 0;
    while(!q.empty()){
        int curr = q.front();
        cnt++;
        q.pop();
        for(auto adjNode : adj[curr]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0){
                q.push(adjNode);
            }
        }
    }
    if(cnt == n)
        return true;
    return false;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<int> adj[n];
    int indegree[n] = {0};
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adj[b].push_back(a);
        indegree[a]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0)
        q.push(i);
    }
    if(isPossibleToComplete(adj, n, q, indegree)){
        cout<<"true";
    }else{
        cout<<"false";
    }
}