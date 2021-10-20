#include<bits/stdc++.h>
using namespace std;

bool ans;

void findPathOfK(int node, int &k, vector<pair<int, int>> adjList[], vector<bool> &visited){
    if(k <= 0) ans = true;
    visited[node] = true;
    for(auto it : adjList[node]){
        int adjNode = it.first;
        int wt = it.second;
        if(!visited[adjNode]){
            k = k - wt;
            findPathOfK(adjNode, k, adjList, visited);
            k = k + wt;
        }
    }
    visited[node] = false;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<pair<int, int>> adjList[n];
    for(int i = 0; i < e; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        adjList[a].push_back({b, wt});
        adjList[b].push_back({a, wt});
    }
    /*
            9 14
            0 1 4
            0 7 8
            1 2 8
            1 7 11
            2 3 7
            2 8 2
            2 5 4
            3 4 9
            3 5 14
            4 5 10
            5 6 2
            6 7 1
            6 8 6
            7 8 7
    */

    int s, k;
    cin>>s>>k;
    vector<bool> visited(n, false);
    // Function to find if there is any path present whose cost is atleast k.
    ans = false;
    findPathOfK(s, k, adjList, visited);
    if(ans) cout<<"true";
    else cout<<"false";
    return 0;
}