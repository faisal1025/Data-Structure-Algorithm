#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long> > &queries, int q){
    vector<long long> pre(n+1);
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        pre[i] = (pre[i-1]+arr[i-1])%mod;
    }

    vector<int> ans;
    for(int i = 0; i < q; i++){
        long long l = queries[i][0]-1;
        long long r = queries[i][1];
        long long r_sum = (((r/n)%mod*pre[n])%mod+pre[r%n])%mod;
        long long l_sum = (((l/n)%mod*pre[n])%mod+pre[l%n])%mod;
        ans.push_back((int) ((r_sum-l_sum+mod)%mod));
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin>>arr[i];
        int q;
        cin>>q;
        vector<vector<long long> > queries(q, vector<long long>(2));
        for(int i = 0; i < q; i++){
            for(int j = 0; j < 2; j++){
                cin>>queries[i][j];
            }
        }

        vector<int> ans = sumInRanges(arr, n, queries, q);
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}