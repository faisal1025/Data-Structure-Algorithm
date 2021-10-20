#include<bits/stdc++.h>
using namespace std;

int main(){
    int V, edges;
    cin>>V>>edges;
    vector<int> adjlist[V];
    for(int i = 0; i < edges; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    for(int i = 0; i < V+1; i++){
        cout<<i<<": ";
        for(auto j: adjlist[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}