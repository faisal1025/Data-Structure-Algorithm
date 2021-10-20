/*
    In Kruskal's Algorithm we use Disjoint set to find cycle if any and union minimum 
    wt edges from given graph.
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int a, int b, int weight){
        u = a;
        v = b;
        wt = weight;
    }
};

bool comp(node a, node b){
    return a.wt < b.wt;
}

int findpar(int node, vector<int> &parent){
    if(node == parent[node]) return node;
    return parent[node] = findpar(parent[node], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank){
    if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else if(rank[v] > rank[u]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    int N, e;
    cin>>N>>e;
    vector<node> edges;
    for(int i = 0; i < e; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        edges.push_back(node(a, b, wt));
    }
    /*
        9 14
        1 7 6
        2 8 2
        2 6 5
        4 0 1
        4 2 5 
        6 8 6
        7 2 3
        7 7 8
        8 0 7
        8 1 2
        9 3 4
        10 5 4
        11 1 7
        14 3 5
    */
    // Overall Time Complexity : O(E log E) + O(e * (4 alpha)) ~= O(E log E) where as 
                                                            // O(e * (4alpha)) is negligible
    // Time to Sort E edges : O(E log E) , where E is no. of edges
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for(int i = 1; i < N; i++){
        parent[i] = i;
    }
    vector<int> rank(N, 0); 
    int cost = 0;
    vector<node> mst;
    // Time Complexity in traversing the through edges : O(e * findpar()) = O(e* (4 alpha))
    for(auto e : edges){
        // findpar func Time Complexity : O(4 alpha)
        int par_u = findpar(e.u, parent);
        int par_v = findpar(e.v, parent);
        if(par_u != par_v){
            cost += e.wt;
            unionn(par_u, par_v, parent, rank);
            mst.push_back(e);
        }
    }
    cout<<"source |"<<"destin |"<<"weight "<<endl;
    for(auto e : mst){
        cout<<e.u<<" | "<<e.v<<" | "<<e.wt<<endl;
    }
    cout<<"Cost of minimum spanning tree is "<<cost;
    return 0;
}
