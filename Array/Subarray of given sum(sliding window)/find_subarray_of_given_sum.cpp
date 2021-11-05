#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    vector<int> findSubarray(int arr[], int n, long long s){
        vector<int> ans;
        int i = 0, j = 0;
        long long sum = arr[0]; 

        while(i < n and j < n){
            if(sum == s){
                ans.push_back(j+1);
                ans.push_back(i+1);
                break;
            }else if(sum < s){
                i++;
                if(i < n) sum += arr[i];
                else break;
            }else{
                sum -= arr[j];
                j++;
            }
        }
        if(ans.size()){
            return ans;
        }else{
            ans.push_back(-1);
            return ans;
        }
    }
};

int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    long long s;
    cin>>s;

    Solution obj;
    vector<int> res = obj.findSubarray(arr, n, s);
    for(auto it : res){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}