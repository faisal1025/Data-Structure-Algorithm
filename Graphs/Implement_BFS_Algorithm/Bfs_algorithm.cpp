#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    public:
    map<T, vector<pair<T, int>> > adjlist;

    void insert(T a, T b, int weight, bool bidirect = true){
        adjlist[a].push_back({b, weight});

        if(bidirect)
            adjlist[b].push_back({a, weight});
    }

    void printGraph(){
        for(auto key: adjlist){
            cout<<key.first<<": ";
            for(auto val: key.second){
                cout<<"("<<val.first<<", "<<val.second<<") ";
            }
            cout<<"\n";
        }
    }

    void bfsGraph(T node){
        queue<T> qt;
        map<T, bool> vis;
        qt.push(node);
        vis[node] = true;
        while(!qt.empty()){
            T curr = qt.front();
            cout<<curr<<" ";
            qt.pop();
            for(auto i: adjlist[curr]){
                if(vis[i.first] == false){
                    qt.push(i.first);
                    vis[i.first] = true;
                }
            }
        }
    }
};

int main(){
    graph<int> g;
    int E, V;
    cin>>V>>E;
    for(int i = 0; i < E; i++){
        int a, b;
        cin>>a>>b;
        g.insert(a, b, 1, 0);
    }
    g.printGraph();
    g.bfsGraph(0);
    return 0;
}
