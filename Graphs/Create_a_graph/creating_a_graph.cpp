#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    public:
    map<T, vector<pair<T, int>> > adjlist;

    void insert(T a, T b, int weight, bool bidirect=1){
        adjlist[a].push_back({b, weight});

        if(bidirect){
            adjlist[b].push_back({a, weight});
        }
    }

    void printAdjlist(){

        for(auto key: adjlist){
            cout<<key.first<<": ";
            for(auto v: key.second){
                cout<<"("<<v.first<<", "<<v.second<<") ";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph<char> g;
    g.insert('1', '0', 5, 0);
    g.insert('1', '2', 4, 0);
    g.insert('1', '3', 3, 0);
    g.insert('1', '4', 2, 0);
    g.printAdjlist();
    return 0;
}