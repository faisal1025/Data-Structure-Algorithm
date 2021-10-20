#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        string topological_sort(unordered_map<char, vector<char> > adj, int indegree[], int N, int K){
            queue<char> q;
            for(int i = 0; i < K; i++){
                if(indegree[i] == 0){
                    char temp = 'a'+i;
                    q.push(temp);
                }
            }

            string ans = "";
            while(!q.empty()){
                char curr = q.front();
                ans.push_back(curr);
                q.pop();
                for(auto adjNode : adj[curr]){
                    indegree[adjNode-'a']--;
                    if(indegree[adjNode-'a'] == 0){
                        q.push(adjNode);
                    }
                }
            }
            return ans;
        }
    public:
        string findOrder(string dict[], int N, int K){
            unordered_map<char, vector<char> >adj;
            int indegree[K] = {0};
            for(int i = 0; i < N-1; i++){
                int m = min(dict[i].length(), dict[i+1].length());
                for(int j = 0; j < m; j++){
                    if(dict[i][j] != dict[i+1][j]){
                        cout<<dict[i][j]<<" "<<dict[i+1][j]<<endl;
                        adj[dict[i][j]].push_back(dict[i+1][j]);
                        indegree[dict[i+1][j]-'a']++;
                        break;
                    } 
                }
            }
            for(auto a:adj){
                cout<<a.first<<" :";
                for(auto m : a.second){
                    cout<<m<<" ";
                }
                cout<<"\n";
            }
            for(int i = 0; i < K; i++){
                cout<<indegree[i]<<endl;
            }

            return topological_sort(adj, indegree, N, K);
        }
};

int main(){
    int N, K;
    cin>>N>>K;
    string dict[N];
    for(int i = 0; i < N; i++){
        cin>>dict[i];
    }
    for(int i = 0; i < N; i++){
        cout<<dict[i]<<" ";
    }
    cout<<endl;

    Solution obj;
    cout<<obj.findOrder(dict, N, K);
    return 0;
}