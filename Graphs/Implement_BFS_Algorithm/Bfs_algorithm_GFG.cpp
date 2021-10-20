#include<bits/stdc++.h>
using namespace std;

vector<int> * createGraph(int V, int edges){
    vector<int> *adjlist = new vector<int>[V];
    for(int i = 0; i < edges; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    return adjlist;
}

void BfsGraph(int V, vector<int> adjlist[]){
    queue<int> q;
    vector<bool> visited(V, false);
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto i : adjlist[curr]){
            if(visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }
    }

}

int main(){
    int V, edges;
    cin>>V>>edges;
    vector<int> *adjlist1 = createGraph(V, edges);
    BfsGraph(V, adjlist1);
}