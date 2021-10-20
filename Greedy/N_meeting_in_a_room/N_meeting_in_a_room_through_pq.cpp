#include<bits/stdc++.h>
using namespace std;

auto it = [](pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
};

class Solution{
    public:
    int maxMeeting( int start[], int end[], int n){
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(it)> pq(it);
        for(int i = 0; i < n; i++){
            pq.push(make_pair(start[i], end[i]));
        }
        vector<pair<int, int>> work;
        while(!pq.empty()){
            work.push_back(pq.top());
            auto j = pq.top();
            pq.pop();
        }

        int i = 0, j = i+1, cnt = 1;
        while(j < n){
            auto task1 = work[i];
            auto task2 = work[j];
            if(task1.second < task2.first){
                cnt++;
                i = j;
            }
            j++;
        }
        return cnt;     
    }
};

int main(){
    int n;
    cin>>n;
    int start[n], end[n];

    for(int i = 0; i < n; i++) cin>>start[i];

    for(int i = 0; i < n; i++) cin>>end[i];

    Solution obj;
    int ans = obj.maxMeeting(start, end, n);
    cout<<ans<<endl;
}