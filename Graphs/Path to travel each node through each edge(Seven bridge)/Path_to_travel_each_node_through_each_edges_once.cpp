#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool findPathDfs(vector<int> adjList[], int V, int node, vector<bool> &visited, int &cnt){
        if(cnt == V) return true;

        visited[node] = true;
        cnt++;
        for(auto adjNode: adjList[node]){
            if(!visited[adjNode]){
                if(findPathDfs(adjList, V, adjNode, visited, cnt)) return true;
            }
        }
        visited[node] = false;
        cnt--;
        return false;
    }

    public:
    bool sevenBridgeProblem(vector<int>adjList[], int V, int s){
        int cnt = 1;
        vector<bool> visited(V, false);
        return findPathDfs(adjList, V, s, visited, cnt);
    }
};

int main (){
    int n, e;
    cin>>n>>e;
    vector<int> adjList[n+1];
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int s;
    cin>>s;
    Solution obj;
    if(obj.sevenBridgeProblem(adjList, n, s)) cout<<"Yes";
    else cout<<"No";
}