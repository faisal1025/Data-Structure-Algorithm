#include<bits/stdc++.h>
using namespace std;

int bellmanFordCycle(int n, vector<vector<int> > edges){
    vector<int> wt(n, INT_MAX);
    wt[0] = 0;

    // Tc = O(N*e)
    for(int i = 0; i < n; i++){
        for(auto e : edges){
            int s = e[0];
            int d = e[1];
            int weight = e[2];
            if(wt[s] != INT_MAX and wt[d] > wt[s]+weight){
                wt[d] = wt[s]+weight;
            }
        }
    }

    for(auto e : edges){
            int s = e[0];
            int d = e[1];
            int weight = e[2];
            if(wt[s] != INT_MAX and wt[d] > wt[s]+weight){
                wt[d] = wt[s]+weight;
                return 1;
            }
    }
    return 0;    
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int> > edges(e);
    for(int i = 0; i < e; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        vector<int> temp = {u, v, wt};
        edges[i] = temp;
    }

    cout<<bellmanFordCycle(n, edges);
    return 0;
}