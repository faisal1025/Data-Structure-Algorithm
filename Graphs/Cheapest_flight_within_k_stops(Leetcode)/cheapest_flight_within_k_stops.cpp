/*
    There are n cities connected by some number of flights. You are given an array flights
    where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city
    fromi to city toi with cost pricei.

    You are also given three integers src, dst, and k, return the cheapest price
    from src to dst with at most k stops. If there is no such route, return -1.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int getCheapestPath(int n, vector<pair<int, int>> adj[], int src, int dst, int k, vector<int> dist){
        queue<pair<int, int>> q;
        q.push({dist[src], src});
        while(!q.empty() and k >= 0){
            k--;
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto cur = q.front();
                int s = cur.second;
                int wt = cur.first;
                q.pop();
                for(auto adjNode: adj[s]){
                    int d = adjNode.first;
                    int cost = adjNode.second;
                    if(dist[d] > wt+cost){
                        dist[d] = wt+cost;
                        q.push({dist[d], d});
                    }
                }
            }
        }
        return dist[dst];
    }

    public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<pair<int, int>> adjList[n];
        for(auto it : flights){
            int s = it[0];
            int d = it[1];
            int wt = it[2];
            adjList[s].push_back({d, wt});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0; 
        return getCheapestPath(n, adjList, src, dst, k, dist);
    }
};

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int> > flights;
    for(int i = 0; i < e; i++){
        int src, dest, wt;
        cin>>src>>dest>>wt;
        flights.push_back({src, dest, wt});
    }
    int src, dst, k;
    cin>>src>>dst>>k;
    Solution obj;
    int ans = obj.findCheapestPrice(n, flights, src, dst, k);
    if(ans == INT_MAX){
        cout<<-1;
    }
    else cout<<ans;
    return 0;
}