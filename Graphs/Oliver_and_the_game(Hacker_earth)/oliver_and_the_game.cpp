/*
    We use the Euler's tour in order to find the is the x is a sub-child of y or not.
    through a function 'is_subtree(x, y);' . if it is true there can be a ans 'yes' 
    bob(y) can find oliver(x) but if x is not the a sub tree of y or y is not a sub-tree 
    of x then it is clear that bob(y) can't find oliver(x).  
*/

#include<bits/stdc++.h>
using namespace std;

int timer = 1;

class Solution{
    private:

    bool is_subtree(int x, int y, int in[], int out[]){
        return in[x] > in[y] and out[x] < out[y];
    }

    public:
    // O(N+E)
    void eulerTour(int node, int in[], int out[], vector<int> adjList[], vector<int> &visited){
        visited[node] = 1;
        in[node] = timer++;

        for(auto adjNode : adjList[node]){
            if(!visited[adjNode]){
                eulerTour(adjNode, in, out, adjList, visited);
            }
        }
        out[node] = timer++;
    }

     
    bool game(int type, int oliver, int bob, vector<int> adjList[], int in[], int out[]){
        if(!is_subtree(oliver, bob, in, out) and !is_subtree(bob, oliver, in, out)){
            return false;
        }else if(type == 0 and is_subtree(bob, oliver, in, out)){
            return true;
        }else if(type == 1 and is_subtree(oliver, bob, in, out)){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> adjList[n+1];
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int in[n+1];
    int out[n+1];
    vector<int> visited(n+1, 0);
    Solution obj;
    obj.eulerTour(1, in, out, adjList, visited);

    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        int type, x, y;
        cin>>type>>x>>y;
        if(obj.game(type, x, y, adjList, in, out)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
