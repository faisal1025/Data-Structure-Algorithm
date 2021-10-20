/*
    There are a total of numCourses courses you have to take, labeled from 0 to 
    numCourses - 1. You are given an array prerequisites where 
    prerequisites[i] = [ai, bi] indicates that you must take course bi first
    if you want to take course ai.

    *For example, the pair [0, 1], indicates that to take course 0 you have to 
    first take course 1.

    mytask - Return true if you can finish all courses. Otherwise, return false.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            int indegree[numCourses] = {0};
            vector<int> adj[numCourses];
            for(auto p : prerequisites){
                adj[p[1]].push_back(p[0]);
                indegree[p[0]]++;
            }

            queue<int> q;
            for(int i = 0; i < numCourses; i++){
                if(indegree[i] == 0)
                q.push(i);
            }

            int cnt = 0;
            while(!q.empty()){
                int curr = q.front();
                cnt++;
                q.pop();
                for(auto dep : adj[curr]){
                    indegree[dep]--;
                    if(indegree[dep] == 0)
                        q.push(dep);
                }
            }

            if(cnt == numCourses)
                return true;
            return false;
        }
};

int main(){
    int num, edges;
    cin>>num>>edges;
    vector<vector<int> > prerequisites;
    for(int i = 0; i < edges; i++){
        int a, b;
        cin>>a>>b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        prerequisites.push_back(temp);
    }

    Solution obj;
    if(obj.canFinish(num, prerequisites))
        cout<<"true";
    else
        cout<<"false";

    return 0; 
}