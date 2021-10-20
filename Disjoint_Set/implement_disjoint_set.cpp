#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(4 alpha)
int findpar(int node, int parent[]){
    if(node == parent[node]) return node;
    return parent[node] = findpar(parent[node], parent); 
}

void unionn(int a, int b, int parent[], int rank[]){
    int par_a = findpar(a, parent);
    int par_b = findpar(b, parent);
    if(par_a != par_b){
        if(rank[a] > rank[b]){
            parent[b] = a;
        }
        else if(rank[b] > rank[a]){
            parent[a] = b;
        }
        else{
            parent[b] = a;
            rank[a]++;
        }
    }
}

int main(){
    int N, e;
    cin>>N>>e;
    int parent[N];
    int rank[N];

    for(int i = 1; i <= N; i++){
        parent[i] = i;
        rank[i] = 0;
    }

    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        unionn(a, b, parent, rank);
    }

    // If we have to find if the two element is of the same component or different
    int u, v;
    cin>>u>>v;
    if(findpar(u, parent) != findpar(v, parent))
        cout<<"Both are not in the same component";
    else
        cout<<"Both are in the same component";
   
    return 0;
}